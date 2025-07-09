#include "Define.h"

Point p = { 41, 17 };		//初始棋盘焦点	x每动一格+/- 5 初始是1  	y每动一格+/-2 初始是1
Point* focus = &p;			//焦点指针（删了也行，不过删了要改挺多地方的）

char Map[YLen][XLen];		//棋盘数组（白盘跟有棋子的盘都是这个数组）

char Chess_Flag = 0;		//棋子颜色标志位	0-棋子颜色为黑 1-棋子颜色为白

char Decide[17][17];		//胜负判定数组

char Message[128];			//消息提示数组
