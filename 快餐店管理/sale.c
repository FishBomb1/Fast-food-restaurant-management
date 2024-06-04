#include "sale.h"


extern struct dish menu[];

void p_sale()
{
	int i = 0, j = 0;
	int n = 0;

	while (menu[n].price != 0) {
		s_table[n] = menu[n];

		n++;
	}
	s_table[n] = menu[n];

	for (i = 0; i < n; i++) {
		for (j = 0; j < n - i; j++) {
			if (s_table[j].sale < s_table[j + 1].sale) {
				temp = s_table[j];
				s_table[j] = s_table[j + 1];
				s_table[j + 1] = temp;

			}
		}
	}
	printf("销量统计图如下：\n");

	i = 0;
	while (menu[i].name[0] != '0') {
		printf("[%d]: %s\t%d份\n", i, menu[i].name, menu[i].sale);
		i++;
	}
}
