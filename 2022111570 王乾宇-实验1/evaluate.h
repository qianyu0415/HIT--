#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<ctype.h>
#include<math.h>

#define MAXSIZE 1000
typedef char ElemType;
typedef int Ele;
typedef struct
{
	Ele data[MAXSIZE];
	int top;	//’ª∂•÷∏’Îa
}SeStack;


bool Push_operator(SeStack* S, ElemType x);
ElemType Pop_operator(SeStack* S);
bool GetTop(SeStack S, ElemType* e);
void InitStack(SeStack* S);
int Is_Empty(SeStack S);
int Get_Precedence(char op);
void nifix_to_suffix(SeStack* stack, char* expression);
Ele Evaluate_Suffix(char* suffix, SeStack* operand);
void print_stack(SeStack* stack);
void print_stack_num(SeStack* stack);
Ele Pop_operand(SeStack *S);
bool Push_operand(SeStack *S, Ele x);

