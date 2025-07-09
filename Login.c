#include "Login.h"
#include "Show.h"
#include "Map.h"

#include "stdio.h"
#include "string.h"

void Focus_Move(Point* focus) {				//焦点移动函数（给焦点加个提示框）
	Map_Flush();
	if (focus->y - 1 == 0) {
		memcpy(Map[focus->y - 1] + focus->x - (((focus->x - 1) / 5) + 1), "┌", 2);
		Map_Move(Map[focus->y - 1], focus->x - (((focus->x - 1) / 5) + 1), 100);
		memcpy(Map[focus->y - 1] + focus->x - (((focus->x - 1) / 5) + 1) + 5, "┐", 2);
		Map_Move(Map[focus->y - 1], focus->x - (((focus->x - 1) / 5) + 1) + 5, 100);
		if (focus->x > 72) {
			Map[focus->y - 1][67] = '\0';
		}
	}
	else {
		memcpy(Map[focus->y - 1] + focus->x - 1, "┌", 2);
		Map_Move(Map[focus->y - 1], focus->x - 1, 100);
		memcpy(Map[focus->y - 1] + focus->x + 5, "┐", 2);
		Map_Move(Map[focus->y - 1], focus->x + 5, 100);
		if (focus->x > 72) {
			Map[focus->y - 1][84] = '\0';
		}
	}
	
	if (focus->y > 30) {
		memcpy(Map[focus->y + 1] + focus->x - (((focus->x - 1) / 5) + 1), "└", 2);
		Map_Move(Map[focus->y + 1], focus->x - (((focus->x - 1) / 5) + 1), 100);
		memcpy(Map[focus->y + 1] + focus->x - (((focus->x - 1) / 5) + 1) + 5, "┘", 2);
		Map_Move(Map[focus->y + 1], focus->x - (((focus->x - 1) / 5) + 1) + 5, 100);
		if (focus->x > 72) {
			Map[focus->y + 1][67] = '\0';
		}
	}
	else {
		memcpy(Map[focus->y + 1] + focus->x - 1, "└", 2);
		Map_Move(Map[focus->y + 1], focus->x - 1, 100);
		memcpy(Map[focus->y + 1] + focus->x + 5, "┘", 2);
		Map_Move(Map[focus->y + 1], focus->x + 5, 100);
		if (focus->x > 72) {
			Map[focus->y + 1][84] = '\0';
		}
	}
	
	show();
}

void Chess_Falling(Point* focus) {				//落子函数（把焦点所在的棋盘制表符替换成棋子字符）
	if (Chess_Flag) {
		if (Decide[(focus->y + 1) / 2][(focus->x + 4) / 5] != 1 && Decide[(focus->y + 1) / 2][(focus->x + 4) / 5] != 2) {
			memcpy(Map[focus->y] + focus->x + 1 + (3 * (focus->x - 1) / 5), "○", 2);	
			Decide[(focus->y + 1) / 2][(focus->x + 4) / 5] = 1;
			strcpy(Message, "当前执棋：白方");
			Chess_Flag = 0;
		}
		else {
			strcpy(Message, "当前位置无法落子！");
		}
		
	}
	else {
		if (Decide[(focus->y + 1) / 2][(focus->x + 4) / 5] != 1 && Decide[(focus->y + 1) / 2][(focus->x + 4) / 5] != 2) {
			memcpy(Map[focus->y] + focus->x + 1 + (3 * (focus->x - 1) / 5), "●", 2);
			Decide[(focus->y + 1) / 2][(focus->x + 4) / 5] = 2;
			strcpy(Message, "当前执棋：黑方");
			Chess_Flag = 1;
		}
		else {
			strcpy(Message, "当前位置无法落子！");
		}
	}
		
	show();

	Is_Win((focus->y + 1) / 2, (focus->x + 4) / 5);
}

void Is_Win(int x, int y) {					//胜负判定函数（笨比懒得想算法就穷举了）
	int Win_Flag = 0;
	while (1) {
	/**********************************Y轴判定***************************************************/
		if (Decide[x][y] == Decide[x - 1][y] && Decide[x][y] == Decide[x - 2][y] && \
			Decide[x][y] == Decide[x - 3][y] && Decide[x][y] == Decide[x - 4][y]){
			printf_s("\n游戏结束！");
			exit(0);
		}
		else if (Decide[x][y] == Decide[x - 1][y] && Decide[x][y] == Decide[x - 2][y] && \
			Decide[x][y] == Decide[x - 3][y] && Decide[x][y] == Decide[x + 1][y]) {
			printf_s("\n游戏结束！");
			exit(0);
		}
		else if (Decide[x][y] == Decide[x - 1][y] && Decide[x][y] == Decide[x - 2][y] && \
			Decide[x][y] == Decide[x + 2][y] && Decide[x][y] == Decide[x + 1][y]) {
			printf_s("\n游戏结束！");
			exit(0);
		}
		else if (Decide[x][y] == Decide[x - 1][y] && Decide[x][y] == Decide[x +3][y] && \
			Decide[x][y] == Decide[x + 2][y] && Decide[x][y] == Decide[x + 1][y]) {
			printf_s("\n游戏结束！");
			exit(0);
		}
		else if (Decide[x][y] == Decide[x + 4][y] && Decide[x][y] == Decide[x + 3][y] && \
			Decide[x][y] == Decide[x + 2][y] && Decide[x][y] == Decide[x + 1][y]) {
			printf_s("\n游戏结束！");
			exit(0);
		}
/************************************X轴判定**************************************************/
		else if (Decide[x][y] == Decide[x][y + 4] && Decide[x][y] == Decide[x][y + 3] && \
			Decide[x][y] == Decide[x][y + 2] && Decide[x][y] == Decide[x][y + 1]) {
			printf_s("\n游戏结束！");
			exit(0);
		}
		else if (Decide[x][y] == Decide[x][y - 1] && Decide[x][y] == Decide[x][y + 3] && \
			Decide[x][y] == Decide[x][y + 2] && Decide[x][y] == Decide[x][y + 1]) {
			printf_s("\n游戏结束！");
			exit(0);
		}
		else if (Decide[x][y] == Decide[x][y - 1] && Decide[x][y] == Decide[x][y - 2] && \
			Decide[x][y] == Decide[x][y + 2] && Decide[x][y] == Decide[x][y + 1]) {
			printf_s("\n游戏结束！");
			exit(0);
		}
		else if (Decide[x][y] == Decide[x][y - 1] && Decide[x][y] == Decide[x][y - 2] && \
			Decide[x][y] == Decide[x][y - 3] && Decide[x][y] == Decide[x][y + 1]) {
			printf_s("\n游戏结束！");
			exit(0);
		}
		else if (Decide[x][y] == Decide[x][y - 1] && Decide[x][y] == Decide[x][y - 2] && \
			Decide[x][y] == Decide[x][y - 3] && Decide[x][y] == Decide[x][y - 4]) {
			printf_s("\n游戏结束！");
			exit(0);
		}
/*************************************对角线判定-左上************************************************/
		else if (Decide[x][y] == Decide[x - 1][y - 1] && Decide[x][y] == Decide[x - 2][y - 2] && \
			Decide[x][y] == Decide[x -3][y - 3] && Decide[x][y] == Decide[x - 4][y - 4]) {
			printf_s("\n游戏结束！");
			exit(0);
		}
		else if (Decide[x][y] == Decide[x - 1][y - 1] && Decide[x][y] == Decide[x - 2][y - 2] && \
			Decide[x][y] == Decide[x - 3][y - 3] && Decide[x][y] == Decide[x + 1][y + 1]) {
			printf_s("\n游戏结束！");
			exit(0);
		}
		else if (Decide[x][y] == Decide[x - 1][y - 1] && Decide[x][y] == Decide[x - 2][y - 2] && \
			Decide[x][y] == Decide[x + 2][y + 2] && Decide[x][y] == Decide[x + 1][y + 1]) {
			printf_s("\n游戏结束！");
			exit(0);
		}
		else if (Decide[x][y] == Decide[x - 1][y - 1] && Decide[x][y] == Decide[x + 3][y + 3] && \
			Decide[x][y] == Decide[x + 2][y + 2] && Decide[x][y] == Decide[x + 1][y + 1]) {
			printf_s("\n游戏结束！");
			exit(0);
		}
		else if (Decide[x][y] == Decide[x + 4][y + 4] && Decide[x][y] == Decide[x + 3][y + 3] && \
			Decide[x][y] == Decide[x + 2][y + 2] && Decide[x][y] == Decide[x + 1][y + 1]) {
			printf_s("\n游戏结束！");
			exit(0);
		}

	/*************************************对角线判定-右上************************************************/
		else if (Decide[x][y] == Decide[x - 1][y + 1] && Decide[x][y] == Decide[x - 2][y + 2] && \
			Decide[x][y] == Decide[x - 3][y + 3] && Decide[x][y] == Decide[x - 4][y + 4]) {
			printf_s("\n游戏结束！");
			exit(0);
		}
		else if (Decide[x][y] == Decide[x - 1][y + 1] && Decide[x][y] == Decide[x - 2][y + 2] && \
			Decide[x][y] == Decide[x - 3][y + 3] && Decide[x][y] == Decide[x + 1][y - 1]) {
			printf_s("\n游戏结束！");
			exit(0);
		}
		else if (Decide[x][y] == Decide[x - 1][y + 1] && Decide[x][y] == Decide[x - 2][y + 2] && \
			Decide[x][y] == Decide[x + 2][y - 2] && Decide[x][y] == Decide[x + 1][y - 1]) {
			printf_s("\n游戏结束！");
			exit(0);
		}
		else if (Decide[x][y] == Decide[x - 1][y + 1] && Decide[x][y] == Decide[x + 3][y - 3] && \
			Decide[x][y] == Decide[x + 2][y - 2] && Decide[x][y] == Decide[x + 1][y - 1]) {
			printf_s("\n游戏结束！");
			exit(0);
		}
		else if (Decide[x][y] == Decide[x + 1][y - 1] && Decide[x][y] == Decide[x + 2][y - 2] && \
			Decide[x][y] == Decide[x + 3][y - 3] && Decide[x][y] == Decide[x + 4][y - 4]) {
			printf_s("\n游戏结束！");
			exit(0);
		}
		return;
	}
}