#pragma once
#include"common.h"

//static int menu_i = 3;//记录菜品编号，能够接在上一次后面添加

struct dish {
	char name[20];
	double price;
	int sale;
};

void MENU();
//void initialization(struct dish menu[]);
void add(struct dish menu[]);
int look(struct dish menu[]);
void delete_(struct dish menu[]);
void modify(struct dish menu[]);
void empty(struct dish menu[]);

