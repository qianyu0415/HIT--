#include<stdio.h>
#include<stdlib.h>
#include"evaluate.h"

void print_stack_num(SeStack* stack)
{
	printf("Õ»×´Ì¬£º"); // ´òÓ¡Õ»×´Ì¬
	for (int k = 0; k <= stack->top; k++) {
		printf("%d ", stack->data[k]);
	}
	printf("\n");
}