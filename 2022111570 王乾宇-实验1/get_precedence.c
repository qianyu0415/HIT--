#include<stdio.h>
#include<stdlib.h>
#include"evaluate.h"

int Get_Precedence(char op)		//获取操作符优先级
{
	if (op == '+' || op == '-')
		return 1;
	else if (op == '*' || op == '/')
		return 2;
	else
		return 0;
}