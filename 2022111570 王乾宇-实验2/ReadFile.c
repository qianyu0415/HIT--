#include"huffman.h"

//分字符读取文件，返回字符总数
void ReadFile(char* array)
{
	FILE* file = fopen("test.txt", "r");
	if (file == NULL)
	{
		printf("打开文件失败。\n");
		return;
	}
	int List[ASC] = { 0 };		//记录频数
	char ch;
	long long i = 0;		//总数
	int total = 0;			//种类数
	//fgetc()逐字从文本中读取信息
	while ((ch = fgetc(file)) != EOF)
	{
		//判断是否为字母字符、标点符号字符、空格、
		if (isalpha(ch) || ispunct(ch) || isspace(ch) || isalnum(ch))
		{
			List[ch]++;
			i++;
			array[i - 1] = ch;
		}

	}
	fclose(file);
	int p = 0;
	for (int k = 0; k < ASC; k++)
	{
		if (List[k] > 0)
		{
			total++;
			Or[p].ch = (char)k;
			Or[p].freg = List[k];

			p++;
		}
	}
	totalch = total;
	countch = i;
}
