#include"huffman.h"

double CalculateAverageCodeLength()
{
	double totalbits = 0;
	for (int i = 0; i < totalch; i++)
	{
		totalbits += strlen(Or[i].code) * Or[i].freg;
	}
	return totalbits / countch;
}