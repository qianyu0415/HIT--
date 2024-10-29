#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "evaluate.h"

Ele Evaluate_Suffix(char* suffix, SeStack* operand)
{
    int i = 0;
    while (suffix[i] != '\0')
    {
        if (isdigit(suffix[i]))
        {
            int num = 0;
            while (isdigit(suffix[i])) 
            {
                num = num * 10 + (suffix[i] - '0');
                i++;
            }
            Push_operand(operand, num);
            printf("ѹ�룺%d\n", num);
            print_stack_num(operand);
        }
        else if (suffix[i] == ' ') 
        {
            i++;
        }
        else 
        {
            char op = suffix[i];
            if (!Is_Empty(*operand) && operand->top >= 1) 
            {
                Ele operand2 = Pop_operand(operand);
                printf("������%d\n", operand2);
                print_stack_num(operand);
                Ele operand1 = Pop_operand(operand);
                printf("������%d\n", operand1);
                print_stack_num(operand);
                Ele result = 0;
                switch (op) 
                {
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
                    if (operand2 != 0) 
                    {
                        result = operand1 / operand2;
                    }
                    else 
                    {
                        printf("������\n");
                        return 0;
                    }
                    break;
                default:
                    printf("δ֪��������%c\n", op);
                    return 0;
                }
                Push_operand(operand, result);
                printf("ѹ�룺%d\n", result);
                print_stack_num(operand);
            }
            else
            {
                printf("��Ч�ĺ�׺���ʽ\n");
                return 0;
            }
            i++;
        }
    }

    if (!Is_Empty(*operand) && operand->top == 0) //ջ��ֻ�����һ��Ԫ��
    {
        Ele popped = Pop_operand(operand);
        printf("������%d\n", popped);
        print_stack_num(operand);
        return popped;
    }
    else 
    {
        printf("��Ч�ĺ�׺���ʽ\n");
        return 0;
    }
}
