#include"huffman.h"

//初始化各节点值
void InitHTree()
{
	for (int i = 0; i < totalch; ++i)
	{
		HTree[i].weight = Or[i].freg;
	}
	for (int i = 0; i < m; i++)
	{
		HTree[i].parent = -1;
		HTree[i].lchild = -1;
		HTree[i].rchild = -1;
	}
}