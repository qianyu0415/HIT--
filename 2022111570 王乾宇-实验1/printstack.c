#include<stdio.h>
#include<stdlib.h>
#include"evaluate.h"

void print_stack(SeStack* stack)
{
	printf("ջ״̬��"); // ��ӡջ״̬
	for (int k = 0; k <= stack->top; k++) {
		printf("%c ", stack->data[k]);
	}
	printf("\n");
}