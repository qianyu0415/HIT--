#include<stdio.h>
#include<stdlib.h>
#include"evaluate.h"

int Get_Precedence(char op)		//��ȡ���������ȼ�
{
	if (op == '+' || op == '-')
		return 1;
	else if (op == '*' || op == '/')
		return 2;
	else
		return 0;
}