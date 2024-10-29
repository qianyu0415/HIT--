#include"huffman.h"

//输出二进制文件
void HuffmanCompress()
{
	FILE* file = fopen("test.txt", "r");
	char ch;
	if (file == NULL)
	{
		printf("无法打开文件\n");
		return;
	}
	FILE* bfile = fopen("CompressedFile.huffman", "wb");
	if (bfile == NULL)
	{
		printf("无法创建压缩文件\n");
		fclose(file);
		return;
	}
	fwrite(&totalch, sizeof(int), 1, bfile);		//把字符总类别数写入
	for (int i = 0; i < totalch; i++)
	{
		fwrite(&Or[i].ch, sizeof(char), 1, bfile);	//把叶子（字符）写入
	}
	for (int i = totalch; i < 2 * totalch - 1; i++)
	{
		fwrite(&HTree[i].lchild, sizeof(unsigned char), 1, bfile);	//把存储的哈夫曼树写入
		fwrite(&HTree[i].rchild, sizeof(unsigned char), 1, bfile);
	}
	fwrite(&countch, sizeof(long long), 1, bfile);	//把字符总数写入



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
		for (index = 0; Or[t].code[index]; ++index)//自上而下输出每个字符的编码
		{
			if (Or[t].code[index] == '0')
				bin = bin << 1;
			else
				bin = (bin << 1) + 1;
			binindex++;
			if (binindex == 8)
			{
				fwrite(&bin, sizeof(bin), 1, bfile);//把字符编码写入
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
