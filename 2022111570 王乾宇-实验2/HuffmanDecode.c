#include"huffman.h"

//解码--从二进制文件中解码
void HuffmanDecode()
{
	FILE* bfile = fopen("CompressedFile.huffman", "rb");
	FILE* file = fopen("OutputText.txt", "w");

	if (bfile == NULL || file == NULL) {
		printf("无法打开压缩文件或输出文件！\n");
		return;
	}

	int total;
	long long count;
	fread(&total, sizeof(int), 1, bfile);
	for (int i = 0; i < total; ++i) {
		fread(&Or[i].ch, sizeof(char), 1, bfile);
	}

	for (int i = total; i < 2 * total - 1; ++i) {
		unsigned char p1, p2;
		fread(&p1, sizeof(unsigned char), 1, bfile);
		fread(&p2, sizeof(unsigned char), 1, bfile);
		HTree[i].lchild = (int)p1;
		HTree[i].rchild = (int)p2;
	}

	fread(&count, sizeof(long long), 1, bfile);

	printf("读入成功！\n");
	printf("这篇文章有%lld个字符，共%d种字符种类数。\n", count, total);

	unsigned char b1;
	fread(&b1, sizeof(unsigned char), 1, bfile);	//读一个字节
	int i = 0;
	int j = 2 * total - 2;	//保证只有一个节点时也能输出
	int ccount = 0;

	while (ccount < count) {
		int bit = (b1 >> (7 - i)) & 1;
		if (bit)	//bit=1
			j = HTree[j].rchild;
		else
			j = HTree[j].lchild;

		++i;
		if (j < total) {
			fprintf(file, "%c", Or[j].ch);
			ccount++;
			j = 2 * total - 2;
		}

		if (i == 8) {
			i = 0;
			fread(&b1, sizeof(unsigned char), 1, bfile);
		}
	}

	fclose(bfile);
	fclose(file);
	printf("解压成功！\n");
}