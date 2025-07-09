#include "stdio.h"
#include "string.h"

#include "Map.h"
#include "Show.h"
#include "Key.h"
#include "Login.h"


int main() {

	Map_Init();			//初始化棋盘（清空成白盘）

	show();				//显示棋盘（打印棋盘数组）
	Focus_Move(focus);	//移动焦点函数（其实就是把焦点框加进数组然后重新打印一次）

	while (1) {
		Key_Scan();		//按键处理函数
	}
	return 0;
}