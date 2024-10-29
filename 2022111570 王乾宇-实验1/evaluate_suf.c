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
            printf("压入：%d\n", num);
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
                printf("弹出：%d\n", operand2);
                print_stack_num(operand);
                Ele operand1 = Pop_operand(operand);
                printf("弹出：%d\n", operand1);
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
                        printf("除以零\n");
                        return 0;
                    }
                    break;
                default:
                    printf("未知操作符：%c\n", op);
                    return 0;
                }
                Push_operand(operand, result);
                printf("压入：%d\n", result);
                print_stack_num(operand);
            }
            else
            {
                printf("无效的后缀表达式\n");
                return 0;
            }
            i++;
        }
    }

    if (!Is_Empty(*operand) && operand->top == 0) //栈里只有最后一个元素
    {
        Ele popped = Pop_operand(operand);
        printf("弹出：%d\n", popped);
        print_stack_num(operand);
        return popped;
    }
    else 
    {
        printf("无效的后缀表达式\n");
        return 0;
    }
}
