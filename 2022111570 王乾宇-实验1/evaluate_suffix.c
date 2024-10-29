#include<stdio.h>
#include<stdlib.h>
#include"evaluate.h"


Ele Evaluate_Suffix(char* suffix)
{
	SeStack operand;	//������ջ
	InitStack(&operand);
	int i = 0;
	while (suffix[i] != '\0')
	{
		//��isdigit����ַ��Ƿ�Ϊʮ�������������ֺ�С����ѹ��ջ
		if (isdigit(suffix[i])||suffix[i]=='.')
		{
			Ele num = strtod(&suffix[i], NULL);
			Push(&operand, num);

			while (isdigit(suffix[i]) ||suffix[i] == '.')
				i++;
		}
		else if (suffix[i] == ' ')
			i++;
		else//������������
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
				printf("δ֪��������%c\n", suffix[i]);
				return 0.0;// δ֪������������Ĭ��ֵ
		}
		Push(&operand, result);
		i++; // �ƶ�ָ���Լ�����ȡ���ʽ
		
	}
		if (!Is_Empty(operand)) {
			return Pop(&operand); // ����ջ��Ӧ��ֻʣ��һ�����ֵ
		}
		else {
			printf("��׺���ʽ��Ч\n");
			return 0.0; // ��׺���ʽ��Ч������Ĭ��ֵ
		}

}