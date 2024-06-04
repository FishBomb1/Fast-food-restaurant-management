#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>
#include"math.h"
int main()
{

	extern int a, b;
	printf("max=%d\n", max(a, b));
	printf("min=%d\n", min(a, b));
}
