#include "MyForm.h"
#include <Windows.h>
#include <iostream>
#include <fstream>
#include <vector>
using namespace LC; 



void Teleport(FLOAT X, FLOAT Y, FLOAT Z)
{
    *(FLOAT*)(*(DWORD*)EntityBase + Xpos) = X;
    *(FLOAT*)(*(DWORD*)EntityBase + Ypos) = Y;
    *(FLOAT*)(*(DWORD*)EntityBase + Zpos) = Z;
}


int Main()
{
    Application::EnableVisualStyles();
    Application::SetCompatibleTextRenderingDefault(false);
    Application::Run(gcnew MyForm); 
    return 0;
}

int HackThread()
{ 
    uintptr_t _EntitiesBase = (uintptr_t)GetModuleHandle(L"EntitiesMP.dll");
    uintptr_t EntityBase = _EntitiesBase + 0x3153D0;
    DWORD Run = 0xDE4;
    DWORD Attack = 0xDD8;
    DWORD Anim = 0xEA4;
    DWORD Xpos = 0x58;
    DWORD Ypos = 0x5c;
    DWORD Zpos = Xpos + 0x08;
    std::vector<int> numbers;
    numbers.push_back(1);
    // ---------------------Target---------------------------
    std::ofstream out;
    out.open("E:\\Programming\\Soft\\test.txt");
    //BYTE* base = (BYTE*)GetModuleHandle(L"Engine.dll");
    //out << base << std::endl;
    //BYTE* ptr = *(BYTE**)(base + 0xD52AB0);
    //out << ptr << std::endl;
    //ptr = *(BYTE**)(ptr + 0x220);
    //out << ptr << std::endl;
    //ptr = *(BYTE**)(ptr + 0x48);
    //out << ptr << std::endl;
    uintptr_t base = (uintptr_t)GetModuleHandle(L"Engine.dll");
    uintptr_t a1 = *(uintptr_t*)(base + 0xD52AB0);
    uintptr_t a2 = *(uintptr_t*)(a1 + 0x48);
    uintptr_t objBase = base + 0xD52AB0;
    DWORD lvl = 0x44;
    DWORD current_hp = 0x40;
    DWORD test = (uintptr_t)GetModuleHandle(L"Engine.dll");
    DWORD check = *(DWORD*)(test + 0xD5F6F4);

    //*(DWORD*)(*(DWORD*)a1 + 0x44);
    // *(DWORD*)(*(DWORD*)a1 + 0x44) LVL OBJECTA
    //float* posX = (float*)(a2 + 0x220);
    //float* posY = (float*)(a2 + 0x224);
    //float* posZ= (float*)(a2 + 0x228);

    int pumpInt = 0;
    int _pumpInt = 0;
    HWND game = FindWindowA(NULL, "Last Chaos (Window 1440x900)");
    while (true)
    {
        if (_Run)
        {
            if (*(FLOAT*)(*(DWORD*)EntityBase + Xpos) > 1 && *(FLOAT*)(*(DWORD*)EntityBase + Xpos) < 5000)
            {
                *(FLOAT*)(*(DWORD*)EntityBase + Run) = LC::Speed;
            }
        }
        if (_Attack)
        {
            if (*(FLOAT*)(*(DWORD*)EntityBase + Xpos) > 1 && *(FLOAT*)(*(DWORD*)EntityBase + Xpos) < 5000)
            {
                *(DWORD*)(*(DWORD*)EntityBase + Attack) = LC::Attspeed;
            }
        }
        if (_NoAnim)
        {
            if (*(DWORD*)(*(DWORD*)EntityBase + Anim))
            {
                *(DWORD*)(*(DWORD*)EntityBase + Anim) = 0;
            }
        }
        if (_TPbot)
        {
            if (GetAsyncKeyState(VK_LBUTTON) & 1)
            {
                Sleep(100);
                uintptr_t a2 = *(uintptr_t*)(a1 + 0x48);
                if (a2 != 0)
                {
                    *(FLOAT*)(*(DWORD*)EntityBase + Xpos) = *(float*)(*(uintptr_t*)(a1 + 0x48) + 0x220);
                    *(FLOAT*)(*(DWORD*)EntityBase + Ypos) = (*(float*)(*(uintptr_t*)(a1 + 0x48) + 0x224) - addPosY);
                    *(FLOAT*)(*(DWORD*)EntityBase + Zpos) = *(float*)(*(uintptr_t*)(a1 + 0x48) + 0x228);
                }
            }
            if (GetAsyncKeyState(0x31) & 1)
            {
                Sleep(100);
                uintptr_t a2 = *(uintptr_t*)(a1 + 0x48);
                if (a2 != 0)
                {
                    *(FLOAT*)(*(DWORD*)EntityBase + Xpos) = *(float*)(*(uintptr_t*)(a1 + 0x48) + 0x220);
                    *(FLOAT*)(*(DWORD*)EntityBase + Ypos) = (*(float*)(*(uintptr_t*)(a1 + 0x48) + 0x224) - addPosY);
                    *(FLOAT*)(*(DWORD*)EntityBase + Zpos) = *(float*)(*(uintptr_t*)(a1 + 0x48) + 0x228);
                }
            }
        }
        if (_Bot)
        {
            //if ((*(FLOAT*)(*(DWORD*)objBase + current_hp)) < 30000)
            PostMessage(game, WM_KEYDOWN, VK_TAB, 0);
            Sleep(50);
            DWORD mobLvl = *(DWORD*)(*(DWORD*)objBase + lvl);
            if ( (min_objLVL < mobLvl) && (mobLvl < max_objLVL) )
            {
                PostMessage(game, WM_KEYDOWN, 0x31, MAKELONG(0, MapVirtualKey(0x31, 0)));
                Sleep(5);
                *(FLOAT*)(*(DWORD*)EntityBase + Xpos) = (*(float*)(*(uintptr_t*)(a1 + 0x48) + 0x220) - addPosX);
                Sleep(5);
                *(FLOAT*)(*(DWORD*)EntityBase + Ypos) = (*(float*)(*(uintptr_t*)(a1 + 0x48) + 0x224) - addPosY);
                Sleep(5);
                *(FLOAT*)(*(DWORD*)EntityBase + Zpos) = *(float*)(*(uintptr_t*)(a1 + 0x48) + 0x228);
                Sleep(600);
                for (int i = 1; i < botAttack; ++i)
                {
                    PostMessage(game, WM_KEYDOWN, 0x31, MAKELONG(0, MapVirtualKey(0x31, 0)));
                    Sleep(50);
                }
                Sleep(40);
                PostMessage(game, WM_KEYDOWN, VK_TAB, 0);
            }

        }
        if (_Pumpkin)
    {

        if (GetAsyncKeyState(VK_SPACE) & 1)
        {
            _pumpInt += 1;
            if (_pumpInt == 10)
            {
                _pumpInt = 1;
            }
            if (_pumpInt == 1)
            {
                Teleport(622, 166, 439);

            }
            if (_pumpInt == 2)
            {
                Teleport(252, 162, 324);

            }
            if (_pumpInt == 3)
            {
                Teleport(193, 163, 973);

            }
            if (_pumpInt == 4)
            {
                Teleport(318, 163, 808);

            }
            if (_pumpInt == 5)
            {
                Teleport(188, 163, 858);

            }
            if (_pumpInt == 6)
            {
                Teleport(401, 167, 967);

            }
            if (_pumpInt == 7)
            {
                Teleport(433, 165, 889);

            }
            if (_pumpInt == 8)
            {
                Teleport(330, 168, 958);

            }
            if (_pumpInt == 9)
            {
                Teleport(806, 169, 594);

            }
        }
        if (GetAsyncKeyState(VK_LSHIFT) & 1)
        {
            pumpInt += 1;
            if (pumpInt == 47)
            {
                pumpInt = 0;
            }
            if (pumpInt == 1)
            {
                Teleport(1573, 102, 594);

            }
            if (pumpInt == 2)
            {
                Teleport(1508, 102, 324);
            }
            if (pumpInt == 3)
            {
                Teleport(1232, 100, 364);
            }
            if (pumpInt == 4)
            {
                Teleport(767, 148, 135);
            }
            if (pumpInt == 5)
            {
                Teleport(658, 154, 216);
            }
            if (pumpInt == 6)
            {
                Teleport(207, 136, 349);
            }
            if (pumpInt == 7)
            {
                Teleport(305, 129, 691);
            }
            if (pumpInt == 8)
            {
                Teleport(384, 132, 810);
            }
            if (pumpInt == 9)
            {
                Teleport(436, 39, 1569);
            }
            if (pumpInt == 10)
            {
                Teleport(276, 50, 1598);
            }
            if (pumpInt == 11)
            {
                Teleport(734, 33, 1697);
            }
            if (pumpInt == 12)
            {
                Teleport(563, 34, 1946);
            }
            if (pumpInt == 13)
            {
                Teleport(447, 45, 2107);
            }
            if (pumpInt == 14)
            {
                Teleport(342, 55, 1977);
            }
            if (pumpInt == 15)
            {
                Teleport(422, 45, 2239);
            }
            if (pumpInt == 16)
            {
                Teleport(728, 45, 2514);
            }
            if (pumpInt == 17)
            {
                Teleport(780, 45, 2570);
            }
            if (pumpInt == 18)
            {
                Teleport(1062, 46, 2716);
            }
            if (pumpInt == 19)
            {
                Teleport(899, 49, 2764);
            }
            if (pumpInt == 20)
            {
                Teleport(891, 40, 2659);
            }
            if (pumpInt == 21)
            {
                Teleport(957, 32, 2390);
            }
            if (pumpInt == 22)
            {
                Teleport(888, 28, 2303);
            }
            if (pumpInt == 23)
            {
                Teleport(800, 29, 2262);
            }
            if (pumpInt == 24)
            {
                Teleport(809, 32, 2167);
            }
            if (pumpInt == 25)
            {
                Teleport(746, 26, 2136);
            }
            if (pumpInt == 26)
            {
                Teleport(1966, 101, 251);
            }
            if (pumpInt == 27)
            {
                Teleport(319, 75, 84);
            }
            if (pumpInt == 28)
            {
                Teleport(289, 79, 138);
            }
            if (pumpInt == 29)
            {
                Teleport(146, 74, 135);
            }
            if (pumpInt == 30)
            {
                Teleport(185, 89, 354);
            }
            if (pumpInt == 31)
            {
                Teleport(320, 92, 320);
            }
            if (pumpInt == 32)
            {
                Teleport(196, 62, 648);
            }
            if (pumpInt == 33)
            {
                Teleport(278, 61, 742);
            }
            if (pumpInt == 34)
            {
                Teleport(145, 69, 860);
            }
            if (pumpInt == 35)
            {
                Teleport(94, 51, 1036);
            }
            if (pumpInt == 36)
            {
                Teleport(70, 63, 1173);
            }
            if (pumpInt == 37)
            {
                Teleport(143, 52, 1165);
            }
            if (pumpInt == 38)
            {
                Teleport(215, 48, 1311);
            }
            if (pumpInt == 39)
            {
                Teleport(91, 50, 1394);
            }
            if (pumpInt == 40)
            {
                Teleport(316, 46, 1295);
            }
            if (pumpInt == 41)
            {
                Teleport(365, 37, 1470);
            }
            if (pumpInt == 42)
            {
                Teleport(220, 43, 1460);
            }
            if (pumpInt == 43)
            {
                Teleport(593, 52, 1451);
            }
            if (pumpInt == 44)
            {
                Teleport(655, 58, 1402);
            }
            if (pumpInt == 45)
            {
                Teleport(798, 64, 1434);
            }
            if (pumpInt == 46)
            {
                Teleport(608, 100, 282);
            }
        }
    }
    Sleep(10);
    }
}
