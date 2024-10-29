#include"huffman.h"

//����--�Ӷ������ļ��н���
void HuffmanDecode()
{
	FILE* bfile = fopen("CompressedFile.huffman", "rb");
	FILE* file = fopen("OutputText.txt", "w");

	if (bfile == NULL || file == NULL) {
		printf("�޷���ѹ���ļ�������ļ���\n");
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

	printf("����ɹ���\n");
	printf("��ƪ������%lld���ַ�����%d���ַ���������\n", count, total);

	unsigned char b1;
	fread(&b1, sizeof(unsigned char), 1, bfile);	//��һ���ֽ�
	int i = 0;
	int j = 2 * total - 2;	//��ֻ֤��һ���ڵ�ʱҲ�����
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
	printf("��ѹ�ɹ���\n");
}