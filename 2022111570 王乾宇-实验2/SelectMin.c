#include"huffman.h"

//ѡȡ������С��
//��ѡ�������޸����Ľ�㣬��ѭ��ѡȡ��Сֵ
void SelectMin(int n, int* p1, int* p2) {
    int i, j;
    for (i = 0; i < n; ++i) {
        if (HTree[i].parent == -1) {
            *p1 = i;
            break;
        }
    }
    for (j = i + 1; j < n; ++j) {
        if (HTree[j].parent == -1) {
            *p2 = j;
            break;
        }
    }
    for (i = *p1; i < n; ++i) {
        if ((HTree[*p1].weight > HTree[i].weight) && (HTree[i].parent == -1) && (*p2 != i)) {
            *p1 = i;
        }
    }
    for (j = *p2; j < n; ++j) {
        if ((HTree[*p2].weight > HTree[j].weight) && (HTree[j].parent == -1) && (*p1 != j)) {
            *p2 = j;
        }
    }
}