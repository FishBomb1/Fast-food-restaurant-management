#define _CRT_SECURE_NO_WARNINGS 1
#include "menu.h"
#include"order.h"
#include"sale.h"
#include"vip.h"

int main()
{
	int i;
	int choice;
	
		//ѡ����Ӧ����
		printf("��ѡ����Ҫ���еĲ�����\n");
		//printf("	����0�˳�\n");
		printf("	����1�����˵��\n");
		printf("	����2�������Ա��̨\n");
		scanf("%d", &i);
		
		if(i==1) order();
		if (i == 2) {
			printf("���ѽ������Ա��̨,��ѡ����Ӧ����\n");
			printf("\t����1�Բ˵����в���\n");
			printf("\t����2�Ի�Ա���в���\n");
			printf("\t����3��������ͳ��\n");
			scanf("%d", &choice);

			switch (choice) {
				case 1: MENU(); break;
				case 2: VIP(); break;
				case 3: p_sale(); break;

			}
		}
	
	return 0;
}