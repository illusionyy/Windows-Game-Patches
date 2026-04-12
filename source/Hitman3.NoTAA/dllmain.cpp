#include "stdafx.h"
#include "helper.hpp"
#include "memory.hpp"

HMODULE baseModule = GetModuleHandle(NULL);

#define wstr(s) L#s
#define wxstr(s) wstr(s)
#define _PROJECT_LOG_PATH _PROJECT_NAME L".log"

wchar_t exePath[_MAX_PATH] = { 0 };

// INI Variables
bool bDisableTAA;
float fSharpness;

void ReadConfig(void)
{
    inipp::Ini<wchar_t> ini;
    // Get game name and exe path
    LOG(_PROJECT_NAME " Built: " __TIME__ " @ " __DATE__ "\n");
    LOG(L"Game Name: %s\n", Memory::GetVersionProductName().c_str());
    LOG(L"Game Path: %s\n", exePath);

    // Initialize config
    // UE4 games use launchers so config path is relative to launcher
    std::wstring config_path = _PROJECT_NAME L".ini";
    std::wifstream iniFile(config_path);
    if (!iniFile)
    {
        // no ini, lets generate one.
        LOG(L"Failed to load config file.\n");
        std::wstring ini_defaults = L"[Settings]\n"
                                    wstr(bDisableTAA)" = true\n"
                                    wstr(fSharpness)" = 0.0\n";
        std::wofstream iniFile(config_path);
        iniFile << ini_defaults;
        bDisableTAA = true;
        fSharpness = 0;
        LOG(L"Created default config file.\n");
    }
    else
    {
        ini.parse(iniFile);
        inipp::get_value(ini.sections[L"Settings"], wstr(bDisableTAA), bDisableTAA);
        inipp::get_value(ini.sections[L"Settings"], wstr(fSharpness), fSharpness);
    }

    // Log config parse
    LOG(L"%s: %s (%i)\n", wstr(bDisableTAA), GetBoolStr(bDisableTAA) , bDisableTAA);
    LOG(L"%s: %.1f\n", wstr(fSharpness), fSharpness);
}

void DisableTAA(void)
{
    // 0000000141227F7C | 3998 08030000 | cmp dword ptr ds : [rax + 308] , ebx  |
    // 0000000141227F82 | 74 04         | je hitman3.141227F88                  |
    // 0000000141227F84 | B1 01         | mov cl, 1                             | --> B1 00         | mov cl, 0                             | 
    // 0000000141227F86 | EB 02         | jmp hitman3.141227F8A                 |

    const unsigned char patch[] = { 0x00 };

    WritePatchPattern(L"39 98 08 03 00 00 74 04", patch, sizeof(patch), L"Disable TAA", 9);
}

void SetCustomSharpness(void)
{
    // 00000001413200D1 | 8B83 B4020000 | mov eax,dword ptr ds:[rbx+2B4]        | --> mov eax, [SharpnessValue]
    //                                                                          | --> nop
    // 00000001413200D7 | 8987 480D0000 | mov dword ptr ds : [rdi + D48] , eax  |

    unsigned char patch[] = { 0xB8, 0x00, 0x00, 0x00, 0x00, 0x90 };

    memcpy(patch + 1, &fSharpness, 4);  // Load custom sharpness
    WritePatchPattern(L"8B 83 B4 02 00 00 89 87 48 0D 00 00", patch, sizeof(patch), L"Set Custom Sharpness", 0);
}

DWORD __stdcall Main(void*)
{
    bLoggingEnabled = false;

    wchar_t LogPath[_MAX_PATH] = { 0 };
    wcscpy_s(exePath, _countof(exePath), GetRunningPath(exePath));
    _snwprintf_s(LogPath, _countof(LogPath), _TRUNCATE, L"%s\\%s", exePath, L"" _PROJECT_LOG_PATH);
    LoggingInit(L"" _PROJECT_NAME, LogPath);
    ReadConfig();

    if (bDisableTAA)
        DisableTAA();
    SetCustomSharpness();

    LOG(L"Shutting down " wstr(fp_log) " file handle.\n");
    fclose(fp_log);
    return true;
}

BOOL APIENTRY DllMain( HMODULE hModule,
                       DWORD  ul_reason_for_call,
                       LPVOID lpReserved
                     )
{
    switch (ul_reason_for_call)
    {
    case DLL_PROCESS_ATTACH:
    {
        CreateThread(NULL, 0, Main, 0, NULL, 0);
    }
    case DLL_THREAD_ATTACH:
    case DLL_THREAD_DETACH:
    case DLL_PROCESS_DETACH:
        break;
    }
    return TRUE;
}
