#include"huffman.h"

//编码
void HuffmanEncoding()
{
	int c, p, i;		//c--孩子,p--双亲
	char cd[1000];	//存放临时编码
	cd[totalch] = '\0';
	int start;		//编码在cd中的位置
	for (i = 0; i < totalch; i++)
	{
		start = totalch;//自下而上，逆溯哈夫曼码
		c = i;
		while ((p = HTree[c].parent) >= 0)
		{
			cd[--start] = (HTree[p].lchild == c) ? '0' : '1';
			c = p;
		}
		strcpy(Or[i].code, &cd[start]);
	}

}
