#include <windows.h>
#include <d3d11.h>
#include "menu.h"

extern void RunMenu(); // ты можешь вынести логику из main.cpp в отдельную функцию

BOOL APIENTRY DllMain(HMODULE hModule, DWORD ul_reason, LPVOID lpReserved) {
    if (ul_reason == DLL_PROCESS_ATTACH) {
        CreateThread(NULL, 0, [](LPVOID) -> DWORD {
            RunMenu(); // здесь инициализация ImGui и рендеринг
            return 0;
        }, NULL, 0, NULL);
    }
    return TRUE;
}