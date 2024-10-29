#include"huffman.h"

//´´½¨Ê÷
void CreateHT()
{
	int i, p1, p2;
	InitHTree();
	int n = totalch;
	for (i = n; i < 2 * n - 1; i++)
	{
		SelectMin(i, &p1, &p2);
		HTree[p1].parent = HTree[p2].parent = i;
		HTree[i].lchild = p1;
		HTree[i].rchild = p2;
		HTree[i].weight = HTree[p1].weight + HTree[p2].weight;
	}
}
