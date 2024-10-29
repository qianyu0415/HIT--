#include<stdio.h>
#include<stdlib.h>
#include"evaluate.h"

int main()
{
	SeStack stack;		//运算符栈
	SeStack operand;	//操作数栈
	InitStack(&operand);
	InitStack(&stack);
	char data[MAXSIZE];		//从文件中读取的表达式
	printf("Read nifix expression from file\n");
	FILE* file = fopen("test.txt", "r");
	if (file == NULL)
	{
		perror("无法打开文件");
		return 1;
	}
	if (fgets(data, sizeof(data), file) == NULL)
	{
		perror("无法读取表达式");
		fclose(file);
	}
	printf("文本中的中缀表达式是：%s\n", data);
	char suffix[MAXSIZE];
	nifix_to_suffix(&stack, data,&suffix);
	Ele result = Evaluate_Suffix(&suffix,&operand);
	printf("%后缀表达式的计算结果：%d", result);

}