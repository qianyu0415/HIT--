#include"huffman.h"

//���ѹ����Ϣ,��������ѹ���ʺ�ʵ��ѹ����
void CompressInformation(char* array)
{
	double Inbits = 8 * countch;
	double Outbits = 0;
	for (int i = 0; i < countch; i++)
	{
		int t;
		int j;
		for (t = 0; t < totalch; t++)
		{
			if (Or[t].ch == array[i])		//����
				break;
		}
		for (j = 0; Or[t].code[j]; j++)
		{
			Outbits += 1;
		}
	}
	printf("����ѹ����Ϊ��%.2lf%%\n", (Outbits / Inbits) * 100);

	struct stat In, Out;		////ȡ��ָ���ļ����ļ�����
	stat("test.txt", &In);		
	stat("CompressedFile.huffman", &Out);
	double Inbitst = In.st_size;		//���ֽ�Ϊ��λ���ļ�����
	double Outbitst = Out.st_size;
	printf("ʵ��ѹ����Ϊ��%.2lf%%\n", (Outbitst / Inbitst) * 100);
}
