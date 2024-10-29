#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<sys/stat.h>
#include<string.h>
#define MAX_READ 10000
#define ASC 128
#define m 2*ASC-1		//2n-1个结点
int totalch;		//字符总类别数
long long countch;	//总字符数

//haffman树的结点，静态三叉链表，每个结点的权重
typedef struct {
	double weight;
	int lchild;
	int rchild;
	int parent;
}HTNode;

typedef struct {
	char ch;		//字符
	int freg;	//频数
	char code[m];	//哈夫曼编码
}Orchar;

HTNode HTree[m];
Orchar Or[ASC];		//记录字符信息


void ReadFile(char* array);
void InitHTree();
void CreateHT();
void SelectMin(int n, int* p1, int* p2);
void HuffmanCompress();
void HuffmanEncoding();
void HuffmanDecode();
void CompressInformation(char* array);
double CalculateAverageCodeLength();
int Compare_File();