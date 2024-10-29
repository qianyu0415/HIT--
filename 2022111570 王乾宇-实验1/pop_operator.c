#include<stdio.h>
#include<stdlib.h>
#include"evaluate.h"

ElemType Pop_operator(SeStack* S)
{
	if (S->top == -1)
		return '\0';
	ElemType x = S->data[S->top];
	S->top--;
	return x;
}