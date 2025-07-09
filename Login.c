#include "Login.h"
#include "Show.h"
#include "Map.h"

#include "stdio.h"
#include "string.h"

void Focus_Move(Point* focus) {				//�����ƶ�������������Ӹ���ʾ��
	Map_Flush();
	if (focus->y - 1 == 0) {
		memcpy(Map[focus->y - 1] + focus->x - (((focus->x - 1) / 5) + 1), "��", 2);
		Map_Move(Map[focus->y - 1], focus->x - (((focus->x - 1) / 5) + 1), 100);
		memcpy(Map[focus->y - 1] + focus->x - (((focus->x - 1) / 5) + 1) + 5, "��", 2);
		Map_Move(Map[focus->y - 1], focus->x - (((focus->x - 1) / 5) + 1) + 5, 100);
		if (focus->x > 72) {
			Map[focus->y - 1][67] = '\0';
		}
	}
	else {
		memcpy(Map[focus->y - 1] + focus->x - 1, "��", 2);
		Map_Move(Map[focus->y - 1], focus->x - 1, 100);
		memcpy(Map[focus->y - 1] + focus->x + 5, "��", 2);
		Map_Move(Map[focus->y - 1], focus->x + 5, 100);
		if (focus->x > 72) {
			Map[focus->y - 1][84] = '\0';
		}
	}
	
	if (focus->y > 30) {
		memcpy(Map[focus->y + 1] + focus->x - (((focus->x - 1) / 5) + 1), "��", 2);
		Map_Move(Map[focus->y + 1], focus->x - (((focus->x - 1) / 5) + 1), 100);
		memcpy(Map[focus->y + 1] + focus->x - (((focus->x - 1) / 5) + 1) + 5, "��", 2);
		Map_Move(Map[focus->y + 1], focus->x - (((focus->x - 1) / 5) + 1) + 5, 100);
		if (focus->x > 72) {
			Map[focus->y + 1][67] = '\0';
		}
	}
	else {
		memcpy(Map[focus->y + 1] + focus->x - 1, "��", 2);
		Map_Move(Map[focus->y + 1], focus->x - 1, 100);
		memcpy(Map[focus->y + 1] + focus->x + 5, "��", 2);
		Map_Move(Map[focus->y + 1], focus->x + 5, 100);
		if (focus->x > 72) {
			Map[focus->y + 1][84] = '\0';
		}
	}
	
	show();
}

void Chess_Falling(Point* focus) {				//���Ӻ������ѽ������ڵ������Ʊ���滻�������ַ���
	if (Chess_Flag) {
		if (Decide[(focus->y + 1) / 2][(focus->x + 4) / 5] != 1 && Decide[(focus->y + 1) / 2][(focus->x + 4) / 5] != 2) {
			memcpy(Map[focus->y] + focus->x + 1 + (3 * (focus->x - 1) / 5), "��", 2);	
			Decide[(focus->y + 1) / 2][(focus->x + 4) / 5] = 1;
			strcpy(Message, "��ǰִ�壺�׷�");
			Chess_Flag = 0;
		}
		else {
			strcpy(Message, "��ǰλ���޷����ӣ�");
		}
		
	}
	else {
		if (Decide[(focus->y + 1) / 2][(focus->x + 4) / 5] != 1 && Decide[(focus->y + 1) / 2][(focus->x + 4) / 5] != 2) {
			memcpy(Map[focus->y] + focus->x + 1 + (3 * (focus->x - 1) / 5), "��", 2);
			Decide[(focus->y + 1) / 2][(focus->x + 4) / 5] = 2;
			strcpy(Message, "��ǰִ�壺�ڷ�");
			Chess_Flag = 1;
		}
		else {
			strcpy(Message, "��ǰλ���޷����ӣ�");
		}
	}
		
	show();

	Is_Win((focus->y + 1) / 2, (focus->x + 4) / 5);
}

void Is_Win(int x, int y) {					//ʤ���ж������������������㷨������ˣ�
	int Win_Flag = 0;
	while (1) {
	/**********************************Y���ж�***************************************************/
		if (Decide[x][y] == Decide[x - 1][y] && Decide[x][y] == Decide[x - 2][y] && \
			Decide[x][y] == Decide[x - 3][y] && Decide[x][y] == Decide[x - 4][y]){
			printf_s("\n��Ϸ������");
			exit(0);
		}
		else if (Decide[x][y] == Decide[x - 1][y] && Decide[x][y] == Decide[x - 2][y] && \
			Decide[x][y] == Decide[x - 3][y] && Decide[x][y] == Decide[x + 1][y]) {
			printf_s("\n��Ϸ������");
			exit(0);
		}
		else if (Decide[x][y] == Decide[x - 1][y] && Decide[x][y] == Decide[x - 2][y] && \
			Decide[x][y] == Decide[x + 2][y] && Decide[x][y] == Decide[x + 1][y]) {
			printf_s("\n��Ϸ������");
			exit(0);
		}
		else if (Decide[x][y] == Decide[x - 1][y] && Decide[x][y] == Decide[x +3][y] && \
			Decide[x][y] == Decide[x + 2][y] && Decide[x][y] == Decide[x + 1][y]) {
			printf_s("\n��Ϸ������");
			exit(0);
		}
		else if (Decide[x][y] == Decide[x + 4][y] && Decide[x][y] == Decide[x + 3][y] && \
			Decide[x][y] == Decide[x + 2][y] && Decide[x][y] == Decide[x + 1][y]) {
			printf_s("\n��Ϸ������");
			exit(0);
		}
/************************************X���ж�**************************************************/
		else if (Decide[x][y] == Decide[x][y + 4] && Decide[x][y] == Decide[x][y + 3] && \
			Decide[x][y] == Decide[x][y + 2] && Decide[x][y] == Decide[x][y + 1]) {
			printf_s("\n��Ϸ������");
			exit(0);
		}
		else if (Decide[x][y] == Decide[x][y - 1] && Decide[x][y] == Decide[x][y + 3] && \
			Decide[x][y] == Decide[x][y + 2] && Decide[x][y] == Decide[x][y + 1]) {
			printf_s("\n��Ϸ������");
			exit(0);
		}
		else if (Decide[x][y] == Decide[x][y - 1] && Decide[x][y] == Decide[x][y - 2] && \
			Decide[x][y] == Decide[x][y + 2] && Decide[x][y] == Decide[x][y + 1]) {
			printf_s("\n��Ϸ������");
			exit(0);
		}
		else if (Decide[x][y] == Decide[x][y - 1] && Decide[x][y] == Decide[x][y - 2] && \
			Decide[x][y] == Decide[x][y - 3] && Decide[x][y] == Decide[x][y + 1]) {
			printf_s("\n��Ϸ������");
			exit(0);
		}
		else if (Decide[x][y] == Decide[x][y - 1] && Decide[x][y] == Decide[x][y - 2] && \
			Decide[x][y] == Decide[x][y - 3] && Decide[x][y] == Decide[x][y - 4]) {
			printf_s("\n��Ϸ������");
			exit(0);
		}
/*************************************�Խ����ж�-����************************************************/
		else if (Decide[x][y] == Decide[x - 1][y - 1] && Decide[x][y] == Decide[x - 2][y - 2] && \
			Decide[x][y] == Decide[x -3][y - 3] && Decide[x][y] == Decide[x - 4][y - 4]) {
			printf_s("\n��Ϸ������");
			exit(0);
		}
		else if (Decide[x][y] == Decide[x - 1][y - 1] && Decide[x][y] == Decide[x - 2][y - 2] && \
			Decide[x][y] == Decide[x - 3][y - 3] && Decide[x][y] == Decide[x + 1][y + 1]) {
			printf_s("\n��Ϸ������");
			exit(0);
		}
		else if (Decide[x][y] == Decide[x - 1][y - 1] && Decide[x][y] == Decide[x - 2][y - 2] && \
			Decide[x][y] == Decide[x + 2][y + 2] && Decide[x][y] == Decide[x + 1][y + 1]) {
			printf_s("\n��Ϸ������");
			exit(0);
		}
		else if (Decide[x][y] == Decide[x - 1][y - 1] && Decide[x][y] == Decide[x + 3][y + 3] && \
			Decide[x][y] == Decide[x + 2][y + 2] && Decide[x][y] == Decide[x + 1][y + 1]) {
			printf_s("\n��Ϸ������");
			exit(0);
		}
		else if (Decide[x][y] == Decide[x + 4][y + 4] && Decide[x][y] == Decide[x + 3][y + 3] && \
			Decide[x][y] == Decide[x + 2][y + 2] && Decide[x][y] == Decide[x + 1][y + 1]) {
			printf_s("\n��Ϸ������");
			exit(0);
		}

	/*************************************�Խ����ж�-����************************************************/
		else if (Decide[x][y] == Decide[x - 1][y + 1] && Decide[x][y] == Decide[x - 2][y + 2] && \
			Decide[x][y] == Decide[x - 3][y + 3] && Decide[x][y] == Decide[x - 4][y + 4]) {
			printf_s("\n��Ϸ������");
			exit(0);
		}
		else if (Decide[x][y] == Decide[x - 1][y + 1] && Decide[x][y] == Decide[x - 2][y + 2] && \
			Decide[x][y] == Decide[x - 3][y + 3] && Decide[x][y] == Decide[x + 1][y - 1]) {
			printf_s("\n��Ϸ������");
			exit(0);
		}
		else if (Decide[x][y] == Decide[x - 1][y + 1] && Decide[x][y] == Decide[x - 2][y + 2] && \
			Decide[x][y] == Decide[x + 2][y - 2] && Decide[x][y] == Decide[x + 1][y - 1]) {
			printf_s("\n��Ϸ������");
			exit(0);
		}
		else if (Decide[x][y] == Decide[x - 1][y + 1] && Decide[x][y] == Decide[x + 3][y - 3] && \
			Decide[x][y] == Decide[x + 2][y - 2] && Decide[x][y] == Decide[x + 1][y - 1]) {
			printf_s("\n��Ϸ������");
			exit(0);
		}
		else if (Decide[x][y] == Decide[x + 1][y - 1] && Decide[x][y] == Decide[x + 2][y - 2] && \
			Decide[x][y] == Decide[x + 3][y - 3] && Decide[x][y] == Decide[x + 4][y - 4]) {
			printf_s("\n��Ϸ������");
			exit(0);
		}
		return;
	}
}