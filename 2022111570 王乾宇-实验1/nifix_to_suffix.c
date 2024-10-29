#include<stdio.h>
#include<stdlib.h>
#include"evaluate.h"

void nifix_to_suffix(SeStack* stack, char* expression, char* suffix)
{
    int j = 0;

    for (int i = 1; expression[i] != '#'; i++)
    {
        char ch = expression[i];

        if (ch == ' ' || ch == '\t')
        {
            // 跳过空格和制表符
            continue;
        }
        else if ((ch >= '0' && ch <= '9') || ch == '.') 
        {
            // 处理数字和小数点
            while ((ch >= '0' && ch <= '9') || ch == '.')
            {
                suffix[j++] = ch;
                i++;
                ch = expression[i];
            }
            suffix[j++] = ' '; // 在数字后面添加一个空格
            i--; // 回退一个字符以处理下一个符号
        }
        else if (ch == '(')
        {
            Push_operator(stack, ch);
            printf("压入:%c\n", ch);
            print_stack(stack);
        }
        else if (ch == ')') 
        {
            while (!Is_Empty(*stack) && stack->data[stack->top] != '(')
            {
                char popped = Pop_operator(stack);
                suffix[j++] = ' '; // 添加空格
                suffix[j++] = popped;
                printf("弹出：%c\n", popped);
                print_stack(stack);
            }
            if (!Is_Empty(*stack) && stack->data[stack->top] == '(') 
            {
                char popped = Pop_operator(stack); // 弹出 '('
                printf("弹出：%c\n", popped);
                print_stack(stack);
            }
        }
        else if (ch == '+' || ch == '-' || ch == '*' || ch == '/')
        {
            while (!Is_Empty(*stack) && Get_Precedence(ch) <= Get_Precedence(stack->data[stack->top]))
            {
                char popped = Pop_operator(stack);
                suffix[j++] = ' '; // 添加空格
                suffix[j++] = popped;
                printf("弹出：%c\n", popped);
                print_stack(stack);
            }
            Push_operator(stack, ch);
            printf("压入:%c\n", ch);
            print_stack(stack);
        }

        suffix[j++] = ' '; // 添加空格
    }

    while (!Is_Empty(*stack))
    {
        char popped = Pop_operator(stack);
        suffix[j++] = ' '; // 添加空格
        suffix[j++] = popped;
        printf("弹出：%c\n", popped);
        print_stack(stack);
    }

    suffix[j] = '\0'; // 添加字符串结束符
    printf("后缀表达式：%s\n", suffix);
}
