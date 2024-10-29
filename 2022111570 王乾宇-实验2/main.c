#define _CRT_SECURE_NO_WARNINGS
#include"huffman.h"
int main()
{
	char array[MAX_READ];
	ReadFile(array);
	CreateHT();
	HuffmanEncoding();
	printf("--------------基于字符的压缩-------------\n");
	printf("这篇文章共有%d个字符，共%d种字符种类数。\n", countch, totalch);
	printf("各字符频数及对应的哈夫曼编码");
	for (int i = 0; i < totalch; i++) 
	{
		printf("\n%c:", Or[i].ch);
		printf("频数: %d\t编码: %s", Or[i].freg, Or[i].code);
	}
	HuffmanCompress();
	printf("\n");
	CompressInformation(array);			//计算压缩率
	double averageCodeLength = CalculateAverageCodeLength();
	printf("平均编码长度：%.2lf比特/字符\n", averageCodeLength);
	HuffmanDecode();
	int result = Compare_File();
	if (result)
		printf("原文件与译码文件相同\n");
	else
		printf("原文件与译码文件不同\n");

	printf("----------------------------------------");
	return 0;
}