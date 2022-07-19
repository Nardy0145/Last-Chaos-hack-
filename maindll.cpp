#include <windows.h>
#pragma comment(lib, "user32.lib")
extern int Main();
extern int HackThread();

void WINAPI MainThread()
{
    Main(); 
}

void WINAPI HckThread()
{
    HackThread();
}
BOOL WINAPI DllMain(HMODULE hModule, DWORD dwReason, LPVOID lpvReserved)
{
    switch (dwReason) {
    case DLL_PROCESS_ATTACH:

        DisableThreadLibraryCalls(hModule);

        if (CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE)MainThread, NULL, 0, NULL) == NULL) {
            return FALSE;
        }
        if (CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE)HckThread, NULL, 0, NULL) == NULL) {
            return FALSE;
        }
        break;

    case DLL_PROCESS_DETACH:
        break;

    case DLL_THREAD_ATTACH:
        break;

    case DLL_THREAD_DETACH:
        break;
    }
    return TRUE;
} 
