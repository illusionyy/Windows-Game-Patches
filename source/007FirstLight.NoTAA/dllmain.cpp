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
                                    wstr(bDisableTAA)" = true";
        std::wofstream iniFile(config_path);
        iniFile << ini_defaults;
        bDisableTAA = true;
        LOG(L"Created default config file.\n");
    }
    else
    {
        ini.parse(iniFile);
        inipp::get_value(ini.sections[L"Settings"], wstr(bDisableTAA), bDisableTAA);
    }

    // Log config parse
    LOG(L"%s: %s (%i)\n", wstr(bDisableTAA), GetBoolStr(bDisableTAA) , bDisableTAA);
}

void DisableTAA(void)
{
    // 0000000140D473CF | 44:38AF A6000000 | cmp byte ptr ds : [rdi + A6] , r13b 
    // 0000000140D473D6 | 75 04            | jne 007firstlight.140D473DC            -->     0000000140D473D6 | 90 | nop
    //                                                                                      0000000140D473D7 | 90 | nop
    // 0000000140D473D8 | 32C9             | xor cl, cl |
    // 0000000140D473DA | EB 3A            | jmp 007firstlight.140D47416 

    const unsigned char patch1[] = { 0x90, 0x90 };

    WritePatchPattern(L"44 38 AF A6 00 00 00 75 04", patch1, sizeof(patch1), L"Disable TAA", 7);

    // 0000000140EC2645 | 45:84F6              | test r14b, r14b |
    // 0000000140EC2648 | 0F84 3C090000        | je 007firstlight.140EC2F8A         -->     0000000140EC2648 | 0F85 3C090000        | jne 007firstlight.140EC2F8A 
    // 0000000140EC264E | 0FB68424 CF000000    | movzx eax, byte ptr ss : [rsp + CF] |
    // 0000000140EC2656 | 4C : 8D8C24 580C0000 | lea r9, qword ptr ss : [rsp + C58] |

    const unsigned char patch2[] = { 0x85 };

    WritePatchPattern(L"45 84 F6 0F 84 ?? ?? ?? ?? 0F B6 84 24 CF 00 00 00", patch2, sizeof(patch2), L"Disable Jitter", 4);
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
