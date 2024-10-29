#include<stdio.h>
#include<stdlib.h>
#include"evaluate.h"

bool GetTop(SeStack S, ElemType* e)
{
	if (S.top == -1)
	{
		return false;
	}
	*e = S.data[S.top];
	return true;

}