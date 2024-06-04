#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<string.h>

static int menu_i = 0;//��¼��Ʒ��ţ��ܹ�������һ�κ������

struct dish {
	char name[20];
	double price;
};

void add(struct dish menu[]);
void look(struct dish menu[]);
void delete_(struct dish menu[]);
void modify(struct dish menu[]);
void empty(struct dish menu[]);
int main()
{
	struct dish menu[50] = { 
		{"����", 15},
		{"����", 8},
		{"����", 5},
		{"0",0}
	// ���Ը�����Ҫ��Ӹ����Ʒ
	};
	
	menu_i = 3;
	int choice;

	printf("��ѡ����Ҫ���б���еĲ�����\n");
	printf("	1����Ӳ�Ʒ\n");
	printf("	2��ɾ����Ʒ\n");
	printf("	3���鿴�˵�\n");
	printf("	4���޸ļ۸�\n");
	printf("	5����ղ˵�\n");
	printf("����0�����\n");


	//ѭ���Բ˵����в���
	do {
		scanf("%d", &choice);   //����ѡ��

		switch (choice) {
			case 1: add(menu); break;
			case 2: delete_(menu); break;
			case 3: look(menu); break;
			case 4: modify(menu); break;
			case 5: empty(menu); break;
			default: printf("���������������\n"); break;
		}
		printf("�������һ������������0��������\n");
	} while (choice != 0);


	return 0;
}
//��Ӳ�Ʒ
void add(struct dish menu[])
{
	int i = menu_i;
	printf("������������ո�����۸����롮0�ո�0������\n");

	//ѭ����Ӳ�Ʒ
	do {
		scanf("%s", menu[i].name);  //��ȡ����

		scanf("%lf", &menu[i].price); //��ȡ�۸�
		//printf("����۸��%s\n", mean[i].name);
		
		//�ж��Ƿ������
		if (menu[i].name[0] == '0') {
			break;
		}

		i++;
		menu_i++;
	} while (1);
	printf("������\n");
}

//ɾ����Ʒ
void delete_(struct dish menu[]) {

	int i = 0;
	int flag = 0;    //��¼�Ƿ��ҵ�
	int index;       //��¼��Ҫɾ��Ԫ�ص��±�
	char a[20];
	//�Ȼ�ȡ
	printf("��������Ҫɾ���Ĳ�Ʒ\n");
	scanf("%s", a);

	//����
	while (menu[i].name[0] != '0') {
		if (strcmp(menu[i].name, a) == 0) {
			index = i;
			flag = 1;
			break;
		}
		i++;
	}
	
	//�ж�
	//��λ
	
	if (flag == 1) {
		while (menu[i].name[0] != '0') {
			strcpy(menu[i].name, menu[i+1].name);  //����ǰ��
			menu[i].price = menu[i + 1].price;       //�۸�ǰ��

			i++;
		}
		menu_i--;

		printf("ɾ���ɹ�\n");
	}
	
	else {
		printf("δ�ҵ���Ҫɾ��Ԫ�أ������Ƿ��������\n");
	}

}

//�鿴�˵�
void look(struct dish menu[])
{
	if (menu_i == 0) {
		printf("��ǰ�˵��ǿյ�\n");
		return 0;
	}
	int i=0;
	while (menu[i].name[0] != '0') {
		printf("[%d]: %s  %.2lf\n", i,menu[i].name, menu[i].price);

		i++;
	}
	printf("����ʾȫ����Ʒ\n");
}

//�޸ļ۸�
void modify(struct dish menu[]) {
	int i=0;
	//int index;
	int flag = 0; 
	char a[20];

	printf("��������Ҫ�޸ļ۸�Ĳ�Ʒ\n");
	scanf("%s", a);

	//����
	while (menu[i].name[0] != '0') {
		if (strcmp(menu[i].name, a) == 0) {
			//index = i;
			flag = 1;
			break;
		}
		i++;
	}
	if (flag == 1) {
		printf("��ǰ�۸�Ϊ��%.2lf\n", menu[i].price);
		printf("��Ҫ�޸�Ϊ���٣�");
		scanf("%lf", &menu[i].price);
		printf("�޸ĳɹ�\n");
	}
	else {
		printf("��Ǹ��δ�ҵ��ò�Ʒ");
	}
		

}

//��ղ˵�
void empty(struct dish menu[])
{
	menu_i = 0;
	strcpy(menu[0].name, "0");
	printf("�˵������\n");
}





















