#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<sys/stat.h>
#include<string.h>
#define MAX_READ 10000
#define ASC 128
#define m 2*ASC-1		//2n-1�����
int totalch;		//�ַ��������
long long countch;	//���ַ���

//haffman���Ľ�㣬��̬��������ÿ������Ȩ��
typedef struct {
	double weight;
	int lchild;
	int rchild;
	int parent;
}HTNode;

typedef struct {
	char ch;		//�ַ�
	int freg;	//Ƶ��
	char code[m];	//����������
}Orchar;

HTNode HTree[m];
Orchar Or[ASC];		//��¼�ַ���Ϣ


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