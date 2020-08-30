#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <vector>
#include <numeric>
#include <limits>
#include<string>
#include<stack>
using namespace std;

typedef struct BiTNode  /* 结点结构 */
{
	char data;		/* 结点数据 */
	struct BiTNode *lchild, *rchild; /* 左右孩子指针 */

}BiTNode, *BiTree;


void createBiTree(BiTree &T, string str, int index) //&的意思是传进来节点指针的引用，括号内等价于 BiTreeNode* &T,目的是让传递进来的指针发生改变
{
	if (index < str.size()) {
		//char ch;
		//scanf("%c", &ch);
		if ('#' == str[index])             //当遇到#时，令树的根节点为NULL，从而结束该分支的递归
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
	printf("%c", T->data);/* 显示结点数据，可以更改为其它对结点操作 */
	PreOrderTraverse(T->lchild); /* 再先序遍历左子树 */
	PreOrderTraverse(T->rchild); /* 最后先序遍历右子树 */
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