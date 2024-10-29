#include"huffman.h"

//����������ļ�
void HuffmanCompress()
{
	FILE* file = fopen("test.txt", "r");
	char ch;
	if (file == NULL)
	{
		printf("�޷����ļ�\n");
		return;
	}
	FILE* bfile = fopen("CompressedFile.huffman", "wb");
	if (bfile == NULL)
	{
		printf("�޷�����ѹ���ļ�\n");
		fclose(file);
		return;
	}
	fwrite(&totalch, sizeof(int), 1, bfile);		//���ַ��������д��
	for (int i = 0; i < totalch; i++)
	{
		fwrite(&Or[i].ch, sizeof(char), 1, bfile);	//��Ҷ�ӣ��ַ���д��
	}
	for (int i = totalch; i < 2 * totalch - 1; i++)
	{
		fwrite(&HTree[i].lchild, sizeof(unsigned char), 1, bfile);	//�Ѵ洢�Ĺ�������д��
		fwrite(&HTree[i].rchild, sizeof(unsigned char), 1, bfile);
	}
	fwrite(&countch, sizeof(long long), 1, bfile);	//���ַ�����д��



	int t;
	unsigned char bin = 0;
	int index;
	int binindex = 0;
	while ((ch = fgetc(file)) != EOF)
	{
		for (t = 0; t < totalch; t++)
		{
			if (Or[t].ch == ch)
				break;
		}
		for (index = 0; Or[t].code[index]; ++index)//���϶������ÿ���ַ��ı���
		{
			if (Or[t].code[index] == '0')
				bin = bin << 1;
			else
				bin = (bin << 1) + 1;
			binindex++;
			if (binindex == 8)
			{
				fwrite(&bin, sizeof(bin), 1, bfile);//���ַ�����д��
				binindex = 0;
				bin = 0;
			}
		}
	}
	if (binindex)
	{
		bin = bin << (8 - binindex);
		fwrite(&bin, sizeof(unsigned char), 1, bfile);
		fwrite(&binindex, sizeof(unsigned char), 1, bfile);
	}
	fclose(file);
	fclose(bfile);
}
