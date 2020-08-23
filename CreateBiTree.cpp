#include "string.h"
#include "stdio.h"    
#include "stdlib.h"   
#include "io.h"  
#include "math.h"  
#include "time.h"
#include <iostream>

#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0

#define MAXSIZE 100 /* 存储空间初始分配量 */

typedef int Status;		/* Status是函数的类型,其值是函数结果状态代码，如OK等 */

typedef char TElemType;
TElemType Nil = ' '; /* 字符型以空格符为空 */

Status visit(TElemType e)
{
	printf("%c ", e);
	return OK;
}

/* 用于构造二叉树********************************** */
int index = 1;
typedef char String[24]; /*  0号单元存放串的长度 */
String str;
////
typedef struct BiTNode  /* 结点结构 */
{
	TElemType data;		/* 结点数据 */
	struct BiTNode *lchild, *rchild; /* 左右孩子指针 */

}BiTNode, *BiTree;    //*BiTree的意思是给 struct node*起了个别名，叫BiTree，故BiTree为指向节点的指针。

/////
Status InitBiTree(BiTree *T)
{
	*T = NULL;
	return OK;
}

/* 按前序输入二叉树中结点的值（一个字符） */
/* #表示空树，构造二叉链表表示二叉树T。 */
void CreateBiTree(BiTree *T)// BiTree 为指向结点struct BiTNode 的指针，因此T为指向指针的指针		
{
	TElemType ch;

	/* scanf("%c",&ch); */
	ch = str[index++];

	if (ch == '#')
		*T = NULL;
	else
	{
		*T = (BiTree)malloc(sizeof(BiTNode));
		if (!*T)
			exit(OVERFLOW);
		(*T)->data = ch; /* 生成根结点 */
		CreateBiTree(&(*T)->lchild); /* 构造左子树 */ //由于T为指向指针的指针，所以(*T)为指向结点的指针
		CreateBiTree(&(*T)->rchild); /* 构造右子树 */
	}
}
//或者可以如下创建一个二叉树
void createBiTree(BiTree &T) //&的意思是传进来节点指针的引用，括号内等价于 BiTreeNode* &T,目的是让传递进来的指针发生改变
{
	char ch;
	scanf("%c", &ch);
	if ('#' == ch)             //当遇到#时，令树的根节点为NULL，从而结束该分支的递归
		T = NULL;
	else
	{
		T = new BiTNode;
		T->data = ch;
		createBiTree(T->lchild);
		createBiTree(T->rchild);
	}
}
