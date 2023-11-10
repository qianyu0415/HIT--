#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<fstream>
using namespace std;
#define ElemType int
const int MAX = 100000;
#define stack_max 10000
typedef struct BSTNode
{
	ElemType data;
	struct BSTNode* lchild, * rchild;
}BSTNode, * BiTree;

//ջ����
typedef struct
{
	BiTree data[stack_max];
	int top;
}SqStack;
void InitStack(SqStack& S)
{
	S.top = -1;
}
void Push(SqStack& S, BiTree key)
{
	if (S.top == stack_max - 1)
	{
		cout << "ջ��������ʧ��";
		return;
	}
	else
		S.data[++S.top] = key;
}
void Pop(SqStack& S, BiTree& key)
{
	if (S.top == -1)
	{
		cout << "ջ�գ���ջʧ��";
		return;
	}
	else
		key = S.data[S.top--];
}
bool IsEmpty(SqStack S)
{
	return S.top == -1;
}
//BST�Ĳ���
BSTNode* BST_Search(BiTree T, ElemType key, int& count)
{
	while (T != NULL)
	{
		count++;
		if (key == T->data) {
			return T; // �ҵ��ˣ����ؽڵ�ָ��
		}
		else if (key < T->data) {
			T = T->lchild;
		}
		else {
			T = T->rchild;
		}
	}
	return NULL; // û�ҵ�������NULL
}
/*
int BST_Insert(BiTree& T, int key)
{
	if (T == NULL)
	{
		T = (BiTree)malloc(sizeof(BSTNode));
		T->data = key;
		T->lchild = T->rchild = NULL;
		return 1;
	}
	else if (key == T->data)
		return 0;
	else if (key < T->data)
		return BST_Insert(T->lchild, key);
	else if (key > T->data)
		return BST_Insert(T->rchild, key);

}*/
//BST�Ĳ������
int BST_Insert(BiTree& T, int key) {
	BiTree parent = NULL;
	BiTree current = T;
	while (current != NULL) {
		parent = current;
		if (key < current->data)
			current = current->lchild;
		else if (key > current->data)
			current = current->rchild;
		else
			return 0; // ����ؼ����Ѵ��ڣ����ز���ʧ��
	}
	BiTree newNode = new BSTNode;
	newNode->data = key;
	newNode->lchild = NULL;
	newNode->rchild = NULL;
	if (parent == NULL)
		T = newNode; // ��Ϊ�գ��½ڵ�Ϊ���ڵ�
	else if (key < parent->data)
		parent->lchild = newNode;
	else
		parent->rchild = newNode;
	return 1; // ����ɹ�
}

//BST�Ĺ���
void Create_BST(BiTree& T, int data[], int n)
{
	T = NULL;
	for (int i = 0; i < n; i++)
	{
		BST_Insert(T, data[i]);
	}
}
//BST��ɾ��
void BST_Delete(BiTree& T, ElemType key) {
	BiTree parent = NULL;
	BiTree current = T;
	while (current != NULL && current->data != key) {
		parent = current;
		if (key < current->data)
			current = current->lchild;
		else
			current = current->rchild;
	}

	if (current == NULL)
		return; // Key not found in the BST

	// Case 1: Node to be deleted has no children
	if (current->lchild == NULL && current->rchild == NULL) {
		if (parent == NULL)
			T = NULL;
		else if (parent->lchild == current)
			parent->lchild = NULL;
		else
			parent->rchild = NULL;
		delete current;
	}
	// Case 2: Node to be deleted has one child
	else if (current->lchild == NULL) {
		if (parent == NULL)
			T = current->rchild;
		else if (parent->lchild == current)
			parent->lchild = current->rchild;
		else
			parent->rchild = current->rchild;
		delete current;
	}
	else if (current->rchild == NULL) {
		if (parent == NULL)
			T = current->lchild;
		else if (parent->lchild == current)
			parent->lchild = current->lchild;
		else
			parent->rchild = current->lchild;
		delete current;
	}
	// Case 3: Node to be deleted has two children
	else {
		// Find the inorder successor (smallest node in the right subtree)
		BiTree successor = current->rchild;
		BiTree successorParent = current;
		while (successor->lchild != NULL) {
			successorParent = successor;
			successor = successor->lchild;
		}

		// Copy the inorder successor's data to the current node
		current->data = successor->data;

		// Delete the inorder successor (it has at most one child)
		if (successorParent->lchild == successor)
			successorParent->lchild = successor->rchild;
		else
			successorParent->rchild = successor->rchild;
		delete successor;
	}
}

void visit(BiTree T)
{
	cout << T->data << " ";
}
void BST_visit(BiTree T)
{
	SqStack S;
	InitStack(S); BiTree p = T;
	while (p || !IsEmpty(S))
	{
		if (p)
		{
			Push(S, p);
			p = p->lchild;
		}
		else
		{
			Pop(S,p); visit(p);
			p = p->rchild;
		}
	}
}

void TimeofSearch(BiTree &T, int data[], int num)
{
	Create_BST(T, data, num);
	int count = 0;//�ɹ��Ĵ���
	int i = 0;//�ɹ������ĸ���
	int count_false = 0;//ʧ�ܵĴ���
	int j = 0;//ʧ�ܵ����ĸ���
	for (int k = 1; k <=2048; k++)
	{
		if (k % 2)
		{
			i++;
			BST_Search(T, k, count);
		}
		else
		{
			j++;
			BST_Search(T, k, count_false);
		}
	}
	double AVLT = (double)count / i;
	double AVLF = (double)count_false / j;
	cout << "���ҳɹ���ƽ�����ҳ���Ϊ:" << AVLT << endl;
	cout << "����ʧ�ܵ�ƽ�����ҳ���Ϊ:" << AVLF << endl;
}
void test(BiTree& T)
{
	cout << endl;
	cout << "BST�Ĳ��롢ɾ�������Һ�����" << endl;
	int insert_key;
	cout << "����������Ԫ��:";
	cin >> insert_key;
	BST_Insert(T, insert_key);
	BST_visit(T);
	cout << endl;
	int delete_key;
	cout << "������ɾ����Ԫ��";
	cin >> delete_key;
	BST_Delete(T, delete_key);
	BST_visit(T);
	cout << endl;
	cout << "��������ҵ�Ԫ��";
	int search_key;
	cin >> search_key;
	int count = 0;
	BiTree p=BST_Search(T, search_key, count);
	if (p == NULL)
		cout << search_key << "û�ҵ�" << endl;
	else
		cout << p->data << "�ҵ���!" << endl;
	cout << "BST��������������:" << endl;
	BST_visit(T);
}
int main()
{
	BiTree T;
	ifstream infile1;
	infile1.open("inputdata1.txt");
	int in;//��ŵ���Ԫ��
	int data[MAX];
	int i = 0;//��¼��������
	while (infile1 >> in)
	{
		data[i++] = in;
	}
	infile1.close();
	TimeofSearch(T, data, i);
	BiTree T2;
	ifstream infile2;
	infile2.open("inputdata2.txt");
	int in_2;
	int data_2[MAX];
	int j = 0;
	while (infile2 >> in_2)
	{
		data_2[j++] = in_2;
	}
	infile2.close();
	TimeofSearch(T2, data_2, j);
	BST_visit(T2);
	test(T);
	
}