#define _CRT_SECURE_NO_WARNINGS
#include"huffman.h"
int main()
{
	char array[MAX_READ];
	ReadFile(array);
	CreateHT();
	HuffmanEncoding();
	printf("--------------�����ַ���ѹ��-------------\n");
	printf("��ƪ���¹���%d���ַ�����%d���ַ���������\n", countch, totalch);
	printf("���ַ�Ƶ������Ӧ�Ĺ���������");
	for (int i = 0; i < totalch; i++) 
	{
		printf("\n%c:", Or[i].ch);
		printf("Ƶ��: %d\t����: %s", Or[i].freg, Or[i].code);
	}
	HuffmanCompress();
	printf("\n");
	CompressInformation(array);			//����ѹ����
	double averageCodeLength = CalculateAverageCodeLength();
	printf("ƽ�����볤�ȣ�%.2lf����/�ַ�\n", averageCodeLength);
	HuffmanDecode();
	int result = Compare_File();
	if (result)
		printf("ԭ�ļ��������ļ���ͬ\n");
	else
		printf("ԭ�ļ��������ļ���ͬ\n");

	printf("----------------------------------------");
	return 0;
}