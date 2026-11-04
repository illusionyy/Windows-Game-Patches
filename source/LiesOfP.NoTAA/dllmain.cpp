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
bool bDisableSharpness;
bool bDisableDOF;

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
                                    wstr(bDisableSharpness)" = true\n"
                                    wstr(bDisableDOF)" = true\n";
        std::wofstream iniFile(config_path);
        iniFile << ini_defaults;
        bDisableTAA = true;
        bDisableSharpness = true;
        bDisableDOF = true;
        LOG(L"Created default config file.\n");
    }
    else
    {
        ini.parse(iniFile);
        inipp::get_value(ini.sections[L"Settings"], wstr(bDisableTAA), bDisableTAA);
        inipp::get_value(ini.sections[L"Settings"], wstr(bDisableSharpness), bDisableSharpness);
        inipp::get_value(ini.sections[L"Settings"], wstr(bDisableDOF), bDisableDOF);
    }

    // Log config parse
    LOG(L"%s: %s (%i)\n", wstr(bDisableTAA), GetBoolStr(bDisableTAA) , bDisableTAA);
    LOG(L"%s: %s (%i)\n", wstr(bDisableSharpness), GetBoolStr(bDisableSharpness), bDisableSharpness);
    LOG(L"%s: %s (%i)\n", wstr(bDisableDOF), GetBoolStr(bDisableDOF), bDisableDOF);
}

void DisableTAA(void)
{
    const unsigned char xor_eax_eax[] = { 0x31, 0xc0, 0x90 };
    WritePatchPattern(L"8B 04 8E 85 C0 79 ?? 33 F6 EB ?? BE 06 00 00 00", xor_eax_eax, sizeof(xor_eax_eax), L"Disable TAA", 0);
}

void DisableSharpness()
{
    // Set r.FidelityFX.FSR.Enabled=0 to disable the forced sharpness
    // 
    // 00007FF7751A30B3 | 8BCB                 | mov ecx, ebx |
    // 00007FF7751A30B5 | 833C8F 00            | cmp dword ptr ds : [rdi + rcx * 4] , 0 
    // 00007FF7751A30B9 | 0F8E 05040000        | jle lop - win64 - shipping.7FF7751A34C4  --> 00007FF7751A30B9 | 0F85 05040000 | jne lop - win64 - shipping.7FF7751A34C4
    // 00007FF7751A30BF | 48 : 89B424 80000000 | mov qword ptr ss : [rsp + 80] , rsi 
    const unsigned char jne[] = { 0x85 };
    WritePatchPattern(L"83 3C 8F 00 0F 8E 05 04 00 00", jne, sizeof(jne), L"Disable FSR", 5);
}

void DisableDOF(void)
{
    // 00007FF7CCB765F5 | 48:8D0D 24A1F003 | lea rcx, qword ptr ds : [7FF7D0A80720] 
    // 00007FF7CCB765FC | 8B0C81           | mov ecx, dword ptr ds : [rcx + rax * 4] 
    // 00007FF7CCB765FF | E8 9CA9FAFF      | call lop - win64 - shipping.7FF7CCB20FA0 
    // 00007FF7CCB76604 | 84C0             | test al, al 
    // 00007FF7CCB76606 | 74 2F            | je lop - win64 - shipping.7FF7CCB76637 
    // 00007FF7CCB76608 | 48 : 8B06        | mov rax, qword ptr ds : [rsi]
    // 00007FF7CCB7660B | F740 28 00400000 | test dword ptr ds : [rax + 28] , 4000 
    // 00007FF7CCB76612 | 74 23            | je lop - win64 - shipping.7FF7CCB76637 
    const unsigned char jne[] = { 0x75 };
    WritePatchPattern(L"8B 0C 81 E8 ?? ?? ?? ?? 84 C0 74 ?? 48 8B ?? F7 40 28 00 40 00 00", jne, sizeof(jne), L"Disable Depth of Field", 10);
}

void Main(void)
{
    bLoggingEnabled = false;
    bDisableTAA = false;
    bDisableDOF = false;
    wchar_t LogPath[_MAX_PATH] = { 0 };
    wcscpy_s(exePath, _countof(exePath), GetRunningPath(exePath));
    _snwprintf_s(LogPath, _countof(LogPath), _TRUNCATE, L"%s\\%s", exePath, _PROJECT_LOG_PATH);
    LoggingInit(_PROJECT_NAME, LogPath);
    ReadConfig();
    if (bDisableTAA)
        DisableTAA();
    if (bDisableDOF)
        DisableDOF();
    if (bDisableSharpness)
        DisableSharpness();
    LOG(L"Shutting down " wstr(fp_log) " file handle.\n");
    fclose(fp_log);
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
        Main();
    }
    case DLL_THREAD_ATTACH:
    case DLL_THREAD_DETACH:
    case DLL_PROCESS_DETACH:
        break;
    }
    return TRUE;
}
