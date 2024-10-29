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
            // �����ո���Ʊ��
            continue;
        }
        else if ((ch >= '0' && ch <= '9') || ch == '.') 
        {
            // �������ֺ�С����
            while ((ch >= '0' && ch <= '9') || ch == '.')
            {
                suffix[j++] = ch;
                i++;
                ch = expression[i];
            }
            suffix[j++] = ' '; // �����ֺ������һ���ո�
            i--; // ����һ���ַ��Դ�����һ������
        }
        else if (ch == '(')
        {
            Push_operator(stack, ch);
            printf("ѹ��:%c\n", ch);
            print_stack(stack);
        }
        else if (ch == ')') 
        {
            while (!Is_Empty(*stack) && stack->data[stack->top] != '(')
            {
                char popped = Pop_operator(stack);
                suffix[j++] = ' '; // ��ӿո�
                suffix[j++] = popped;
                printf("������%c\n", popped);
                print_stack(stack);
            }
            if (!Is_Empty(*stack) && stack->data[stack->top] == '(') 
            {
                char popped = Pop_operator(stack); // ���� '('
                printf("������%c\n", popped);
                print_stack(stack);
            }
        }
        else if (ch == '+' || ch == '-' || ch == '*' || ch == '/')
        {
            while (!Is_Empty(*stack) && Get_Precedence(ch) <= Get_Precedence(stack->data[stack->top]))
            {
                char popped = Pop_operator(stack);
                suffix[j++] = ' '; // ��ӿո�
                suffix[j++] = popped;
                printf("������%c\n", popped);
                print_stack(stack);
            }
            Push_operator(stack, ch);
            printf("ѹ��:%c\n", ch);
            print_stack(stack);
        }

        suffix[j++] = ' '; // ��ӿո�
    }

    while (!Is_Empty(*stack))
    {
        char popped = Pop_operator(stack);
        suffix[j++] = ' '; // ��ӿո�
        suffix[j++] = popped;
        printf("������%c\n", popped);
        print_stack(stack);
    }

    suffix[j] = '\0'; // ����ַ���������
    printf("��׺���ʽ��%s\n", suffix);
}
