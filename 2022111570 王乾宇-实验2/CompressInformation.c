#include"huffman.h"

//输出压缩信息,计算理论压缩率和实际压缩率
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
			if (Or[t].ch == array[i])		//查码
				break;
		}
		for (j = 0; Or[t].code[j]; j++)
		{
			Outbits += 1;
		}
	}
	printf("理论压缩率为：%.2lf%%\n", (Outbits / Inbits) * 100);

	struct stat In, Out;		////取得指定文件的文件属性
	stat("test.txt", &In);		
	stat("CompressedFile.huffman", &Out);
	double Inbitst = In.st_size;		//以字节为单位的文件容量
	double Outbitst = Out.st_size;
	printf("实际压缩率为：%.2lf%%\n", (Outbitst / Inbitst) * 100);
}
