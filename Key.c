#include "Key.h"
#include "Login.h"

#include "stdio.h"
#include "Windows.h"

void Key_Scan() {
    if (GetAsyncKeyState(VK_UP) & 0x8000) {
        if (focus->y > 2)
            focus->y -= 2;
        Focus_Move(focus);
        Sleep(250);
    }

    if (GetAsyncKeyState(VK_DOWN) & 0x8000) {
        if (focus->y < YLen - 2)
            focus->y += 2;
        Focus_Move(focus);
        Sleep(250);
    }

    if (GetAsyncKeyState(VK_LEFT) & 0x8000) {
        if (focus->x > 5)
            focus->x -= 5;
        Focus_Move(focus);
        Sleep(250);
    }

    if (GetAsyncKeyState(VK_RIGHT) & 0x8000) {
        if (focus->x < 72)
            focus->x += 5;
        Focus_Move(focus);
        Sleep(250);
    }

    if (GetAsyncKeyState(VK_ESCAPE) & 0x8000) {
        system("cls");
        for (int i = 0; i < 16; i++) {
            for (int j = 0; j < 16; j++){
                printf_s("%d", Decide[i][j]);
            }
            printf_s("\n");
        }
        exit(0);
    }

    if (GetAsyncKeyState(VK_SPACE) & 0x8000) {
        Chess_Falling(focus);
        Sleep(250);
    }

    if (GetAsyncKeyState(VK_SHIFT) & 0x8000) {
        for (int i = 0; i < 16; i++) {
            printf_s("%s", Decide[i]);
        }
        Sleep(250);
    }
}