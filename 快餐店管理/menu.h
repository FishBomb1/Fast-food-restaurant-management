#pragma once
#include"common.h"

//static int menu_i = 3;//��¼��Ʒ��ţ��ܹ�������һ�κ������

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

