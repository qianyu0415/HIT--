#include<stdio.h>
#include<stdlib.h>
#include"evaluate.h"

int Is_Empty(SeStack S)
{
    return S.top == -1;//若为空返回1，反之返回0
}