#define _CRT_SECURE_NO_WARNINGS 1
#include"order.h"

extern struct dish menu[];

int order() {
	double sum = 0;  //计算总金额
	int i,count=0;

	look(menu);  //显示菜单
	printf("\n");

	printf("请选择您需要的菜品的序号，用空行隔开：,输入-1结束\n");

	while (1) {
		scanf("%d",&i);
		if (i == -1) break;

		sum += menu[i].price;  //计算总金额

		//账单
		bill[count].price = menu[i].price;
		strcpy(bill[count].name, menu[i].name);

		//销量
		menu[i].sale++;

		count++;
	}
	//是否为会员
	printf("您是否为会员，如果是请输入手机号，如果不是请输入0\n");
	if (findMember() == 1) sum *= 0.9;

	P_bill(sum,count);
	printf("是否结算，输入1结算，输入0取消订单\n");
	scanf("%d", &i);
	if (i == 1) {
		printf("结算成功，欢迎下次光临\n");
		return 0;
	}
	else {
		printf("取消成功\n");
	}
}

void P_bill(double sum,int count)
{
	int i;

	printf("您的账单为：\n");
	for (i = 0; i < count; i++) {
		printf("[%d]:%s\t%.2lf\n", i, bill[i].name, bill[i].price);		
	}
	printf("共计：%.2lf\n", sum);

}