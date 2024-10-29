#include<stdio.h>
#include<stdlib.h>
#include"evaluate.h"

bool Push_operator(SeStack* S, ElemType x)
{
	if (S->top == MAXSIZE - 1)
		return false;
	S->top = S->top + 1;
	S->data[S->top] = x;
	return true;

}