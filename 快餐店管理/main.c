#define _CRT_SECURE_NO_WARNINGS 1
#include "menu.h"
#include"order.h"
#include"sale.h"
#include"vip.h"

int main()
{
	int i;
	int choice;
	
		//选择相应操作
		printf("请选择需要进行的操作：\n");
		//printf("	输入0退出\n");
		printf("	输入1给客人点餐\n");
		printf("	输入2进入管理员后台\n");
		scanf("%d", &i);
		
		if(i==1) order();
		if (i == 2) {
			printf("您已进入管理员后台,请选择相应操作\n");
			printf("\t输入1对菜单进行操作\n");
			printf("\t输入2对会员进行操作\n");
			printf("\t输入3进行销量统计\n");
			scanf("%d", &choice);

			switch (choice) {
				case 1: MENU(); break;
				case 2: VIP(); break;
				case 3: p_sale(); break;

			}
		}
	
	return 0;
}