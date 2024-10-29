#include<stdio.h>
#include<stdlib.h>
#include"evaluate.h"

Ele Pop_operand(SeStack* S)
{
	if (S->top == -1)
		return 0.0;
	Ele x = S->data[S->top];
	S->top--;
	return x;
}