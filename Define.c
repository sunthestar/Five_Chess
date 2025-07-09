#include "Define.h"

Point p = { 41, 17 };		//棋盘变量	x一格 5 初始 1  	y一格 2 初始 1
Point* focus = &p;

char Map[YLen][XLen];

char Chess_Flag = 0;		//棋子颜色标志位	0-棋子颜色为黑 1-棋子颜色为白

char Decide[17][17];		//胜负判定数组

char Message[128];			//消息提示数组
