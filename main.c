#include "stdio.h"
#include "string.h"

#include "Map.h"
#include "Show.h"
#include "Key.h"
#include "Login.h"


int main() {

	Map_Init();			//��ʼ�����̣���ճɰ��̣�

	show();				//��ʾ���̣���ӡ�������飩
	Focus_Move(focus);	//�ƶ����㺯������ʵ���ǰѽ����ӽ�����Ȼ�����´�ӡһ�Σ�

	while (1) {
		Key_Scan();		//����������
	}
	return 0;
}