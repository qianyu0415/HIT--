#include<stdio.h>
#include<stdlib.h>
#include"evaluate.h"

void print_stack_num(SeStack* stack)
{
	printf("ջ״̬��"); // ��ӡջ״̬
	for (int k = 0; k <= stack->top; k++) {
		printf("%d ", stack->data[k]);
	}
	printf("\n");
}