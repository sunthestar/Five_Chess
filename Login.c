#include "Login.h"
#include "Show.h"
#include "Map.h"

#include "stdio.h"
#include "string.h"

void Focus_Move(Point* focus) {
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

void Chess_Falling(Point* focus) {
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
}

void Is_Win(void) {
	//if()
}