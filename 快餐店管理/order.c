#define _CRT_SECURE_NO_WARNINGS 1
#include"order.h"

extern struct dish menu[];

int order() {
	double sum = 0;  //�����ܽ��
	int i,count=0;

	look(menu);  //��ʾ�˵�
	printf("\n");

	printf("��ѡ������Ҫ�Ĳ�Ʒ����ţ��ÿ��и�����,����-1����\n");

	while (1) {
		scanf("%d",&i);
		if (i == -1) break;

		sum += menu[i].price;  //�����ܽ��

		//�˵�
		bill[count].price = menu[i].price;
		strcpy(bill[count].name, menu[i].name);

		//����
		menu[i].sale++;

		count++;
	}
	//�Ƿ�Ϊ��Ա
	printf("���Ƿ�Ϊ��Ա��������������ֻ��ţ��������������0\n");
	if (findMember() == 1) sum *= 0.9;

	P_bill(sum,count);
	printf("�Ƿ���㣬����1���㣬����0ȡ������\n");
	scanf("%d", &i);
	if (i == 1) {
		printf("����ɹ�����ӭ�´ι���\n");
		return 0;
	}
	else {
		printf("ȡ���ɹ�\n");
	}
}

void P_bill(double sum,int count)
{
	int i;

	printf("�����˵�Ϊ��\n");
	for (i = 0; i < count; i++) {
		printf("[%d]:%s\t%.2lf\n", i, bill[i].name, bill[i].price);		
	}
	printf("���ƣ�%.2lf\n", sum);

}