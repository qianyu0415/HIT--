#include"huffman.h"

//���ַ���ȡ�ļ��������ַ�����
void ReadFile(char* array)
{
	FILE* file = fopen("test.txt", "r");
	if (file == NULL)
	{
		printf("���ļ�ʧ�ܡ�\n");
		return;
	}
	int List[ASC] = { 0 };		//��¼Ƶ��
	char ch;
	long long i = 0;		//����
	int total = 0;			//������
	//fgetc()���ִ��ı��ж�ȡ��Ϣ
	while ((ch = fgetc(file)) != EOF)
	{
		//�ж��Ƿ�Ϊ��ĸ�ַ����������ַ����ո�
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
