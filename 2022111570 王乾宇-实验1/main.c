#include<stdio.h>
#include<stdlib.h>
#include"evaluate.h"

int main()
{
	SeStack stack;		//�����ջ
	SeStack operand;	//������ջ
	InitStack(&operand);
	InitStack(&stack);
	char data[MAXSIZE];		//���ļ��ж�ȡ�ı��ʽ
	printf("Read nifix expression from file\n");
	FILE* file = fopen("test.txt", "r");
	if (file == NULL)
	{
		perror("�޷����ļ�");
		return 1;
	}
	if (fgets(data, sizeof(data), file) == NULL)
	{
		perror("�޷���ȡ���ʽ");
		fclose(file);
	}
	printf("�ı��е���׺���ʽ�ǣ�%s\n", data);
	char suffix[MAXSIZE];
	nifix_to_suffix(&stack, data,&suffix);
	Ele result = Evaluate_Suffix(&suffix,&operand);
	printf("%��׺���ʽ�ļ�������%d", result);

}