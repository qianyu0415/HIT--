#include<stdio.h>
#include<stdlib.h>
#include"evaluate.h"


Ele Evaluate_Suffix(char* suffix)
{
	SeStack operand;	//操作数栈
	InitStack(&operand);
	int i = 0;
	while (suffix[i] != '\0')
	{
		//用isdigit检查字符是否为十进制数，把数字和小数点压进栈
		if (isdigit(suffix[i])||suffix[i]=='.')
		{
			Ele num = strtod(&suffix[i], NULL);
			Push(&operand, num);

			while (isdigit(suffix[i]) ||suffix[i] == '.')
				i++;
		}
		else if (suffix[i] == ' ')
			i++;
		else//遇到操作符了
		{
			Ele operand2 = Pop(&operand);
			Ele operand1 = Pop(&operand);
			float result = 0.0;
			switch (suffix[i]) {
			case '+':
				result = operand1 + operand2;
				break;
			case '-':
				result = operand1 - operand2;
				break;
			case '*':
				result = operand1 * operand2;
				break;
			case '/':
				result = operand1 / operand2;
				break;
			default:
				printf("未知操作符：%c\n", suffix[i]);
				return 0.0;// 未知操作符，返回默认值
		}
		Push(&operand, result);
		i++; // 移动指针以继续读取表达式
		
	}
		if (!Is_Empty(operand)) {
			return Pop(&operand); // 最终栈中应该只剩下一个结果值
		}
		else {
			printf("后缀表达式无效\n");
			return 0.0; // 后缀表达式无效，返回默认值
		}

}