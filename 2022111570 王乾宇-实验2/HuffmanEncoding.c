#include"huffman.h"

//����
void HuffmanEncoding()
{
	int c, p, i;		//c--����,p--˫��
	char cd[1000];	//�����ʱ����
	cd[totalch] = '\0';
	int start;		//������cd�е�λ��
	for (i = 0; i < totalch; i++)
	{
		start = totalch;//���¶��ϣ����ݹ�������
		c = i;
		while ((p = HTree[c].parent) >= 0)
		{
			cd[--start] = (HTree[p].lchild == c) ? '0' : '1';
			c = p;
		}
		strcpy(Or[i].code, &cd[start]);
	}

}
