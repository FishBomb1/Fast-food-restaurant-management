#define _CRT_SECURE_NO_WARNINGS 1
#include"common.h"
#include"menu.h"
#include"vip.h"

struct Bill{
	char name[20];
	double price;

}bill[50];

int order();
void P_bill(double sum,int count);