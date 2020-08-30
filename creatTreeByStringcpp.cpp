#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <vector>
#include <numeric>
#include <limits>
#include<string>
#include<stack>
using namespace std;

typedef struct BiTNode  /* ���ṹ */
{
	char data;		/* ������� */
	struct BiTNode *lchild, *rchild; /* ���Һ���ָ�� */

}BiTNode, *BiTree;


void createBiTree(BiTree &T, string str, int index) //&����˼�Ǵ������ڵ�ָ������ã������ڵȼ��� BiTreeNode* &T,Ŀ�����ô��ݽ�����ָ�뷢���ı�
{
	if (index < str.size()) {
		//char ch;
		//scanf("%c", &ch);
		if ('#' == str[index])             //������#ʱ�������ĸ��ڵ�ΪNULL���Ӷ������÷�֧�ĵݹ�
			T = NULL;
		else
		{
			T = new BiTNode;
			T->data = str[index];
			createBiTree(T->lchild,str,index++);
			createBiTree(T->rchild,str,index++);
		}
	}
}

void PreOrderTraverse(BiTree T)
{
	if (T == NULL)
		return;
	printf("%c", T->data);/* ��ʾ������ݣ����Ը���Ϊ�����Խ����� */
	PreOrderTraverse(T->lchild); /* ��������������� */
	PreOrderTraverse(T->rchild); /* ���������������� */
}

int main_crec()
{
	string str;
	cout << "please entry string" << endl;
	cin >> str;

	BiTree T;
	createBiTree(T, str, 0);
	PreOrderTraverse(T);

	getchar();

	return 0;
}