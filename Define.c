#include "Define.h"

Point p = { 41, 17 };		//���̱���	xһ�� 5 ��ʼ 1  	yһ�� 2 ��ʼ 1
Point* focus = &p;

char Map[YLen][XLen];

char Chess_Flag = 0;		//������ɫ��־λ	0-������ɫΪ�� 1-������ɫΪ��

char Decide[17][17];		//ʤ���ж�����

char Message[128];			//��Ϣ��ʾ����
