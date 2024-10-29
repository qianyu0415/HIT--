#include<stdio.h>
#include<stdlib.h>
#include"evaluate.h"

bool Push_operand(SeStack* S, Ele x)
{
	if (S->top == MAXSIZE - 1)
		return false;
	S->top = S->top + 1;
	S->data[S->top] = x;
	return true;

}