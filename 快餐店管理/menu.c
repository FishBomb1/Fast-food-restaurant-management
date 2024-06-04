#define _CRT_SECURE_NO_WARNINGS 1
#include "menu.h"

static int menu_i = 3;//记录菜品编号，能够接在上一次后面添加

struct dish menu[50] = {
	{"汉堡", 15,1},
	{"薯条", 8,2},
	{"可乐", 5,3},
	{"0",0,0},
	// 可以根据需要添加更多菜品
};

void MENU() {
	//initialization(menu);
	int choice;

	printf("请选择您要对列表进行的操作：\n");
	printf("	1：添加菜品\n");
	printf("	2：删除菜品\n");
	printf("	3：查看菜单\n");
	printf("	4：修改价格\n");
	printf("	5：清空菜单\n");
	printf("输入0后结束\n");


	//循环对菜单进行操作
	do {
		scanf("%d", &choice);   //输入选择

		if (choice == 0) break;

		switch (choice) {
		case 1: add(menu); break;
		case 2: delete_(menu); break;
		case 3: look(menu); break;
		case 4: modify(menu); break;
		case 5: empty(menu); break;
		default: printf("错误操作，请重试\n"); break;
		}
		printf("请进行下一步操作，输入0结束操作\n");
	} while (1);
}

//初始化
//void initialization(struct dish menu[]) {
//	strcpy(menu[0].name, "a");
//	menu[0].price = 1;
//	strcpy(menu[1].name, "b");
//	menu[1].price = 2;
//	strcpy(menu[2].name, "c");
//	menu[2].price = 3;
//	strcpy(menu[3].name, "0");
//	menu_i = 3;
//}

void add(struct dish menu[])
{
	int i = menu_i;
	printf("先输入菜名，空格输入价格，输入‘0空格0’结束\n");

	//循环添加菜品
	do {
		scanf("%s", menu[i].name);  //获取菜名

		scanf("%lf", &menu[i].price); //获取价格
		//printf("输入价格后：%s\n", mean[i].name);

		//判断是否结束了
		if (menu[i].name[0] == '0') {
			break;
		}

		i++;
		menu_i++;
	} while (1);
	printf("添加完毕\n");
}

//删除菜品
void delete_(struct dish menu[]) {

	int i = 0;
	int flag = 0;    //记录是否找到
	int index;       //记录需要删除元素的下标
	char a[20];
	//先获取
	printf("请输入需要删除的菜品\n");
	scanf("%s", a);

	//查找
	while (menu[i].name[0] != '0') {
		if (strcmp(menu[i].name, a) == 0) {
			index = i;
			flag = 1;
			break;
		}
		i++;
	}

	//判断
	//移位

	if (flag == 1) {
		while (menu[i].name[0] != '0') {
			strcpy(menu[i].name, menu[i + 1].name);  //菜名前移
			menu[i].price = menu[i + 1].price;       //价格前移

			i++;
		}
		menu_i--;

		printf("删除成功\n");
	}

	else {
		printf("未找到需要删除元素，请检查是否输入错误\n");
	}

}

//查看菜单
int look(struct dish menu[])
{
	if (menu_i == 0) {
		printf("当前菜单是空的\n");
		return 0;
	}
	int i = 0;
	while (menu[i].name[0] != '0') {
		printf("[%d]: %s\t%.2lf\n", i, menu[i].name, menu[i].price);

		i++;
	}
	printf("已显示全部菜品\n");
}

//修改价格
void modify(struct dish menu[]) {
	int i = 0;
	//int index;
	int flag = 0;
	char a[20];

	printf("请输入需要修改价格的菜品\n");
	scanf("%s", a);

	//查找
	while (menu[i].name[0] != '0') {
		if (strcmp(menu[i].name, a) == 0) {
			//index = i;
			flag = 1;
			break;
		}
		i++;
	}
	if (flag == 1) {
		printf("当前价格为：%.2lf\n", menu[i].price);
		printf("您要修改为多少：");
		scanf("%lf", &menu[i].price);
		printf("修改成功\n");
	}
	else {
		printf("抱歉，未找到该菜品");
	}


}

//清空菜单
void empty(struct dish menu[])
{
	menu_i = 0;
	strcpy(menu[0].name, "0");
	printf("菜单已清空\n");
}
