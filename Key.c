#include "Key.h"
#include "Login.h"

#include "stdio.h"
#include "Windows.h"

void Key_Scan() {       //按键逻辑函数（其实就是键盘扫描然后扫描完了改焦点坐标然后调焦点移动函数）
    if (GetAsyncKeyState(VK_UP) & 0x8000) {         //上键
        if (focus->y > 2)
            focus->y -= 2;
        Focus_Move(focus);
        Sleep(250);
    }

    if (GetAsyncKeyState(VK_DOWN) & 0x8000) {       //下键
        if (focus->y < YLen - 2)
            focus->y += 2;
        Focus_Move(focus);
        Sleep(250);
    }

    if (GetAsyncKeyState(VK_LEFT) & 0x8000) {       //左键
        if (focus->x > 5)
            focus->x -= 5;
        Focus_Move(focus);
        Sleep(250);
    }

    if (GetAsyncKeyState(VK_RIGHT) & 0x8000) {      //右键
        if (focus->x < 72)
            focus->x += 5;
        Focus_Move(focus);
        Sleep(250);
    }

    if (GetAsyncKeyState(VK_ESCAPE) & 0x8000) {     //ESC退出程序
        exit(0);
    }

    if (GetAsyncKeyState(VK_SPACE) & 0x8000) {      //空格落子
        Chess_Falling(focus);
        Sleep(250);
    }
}