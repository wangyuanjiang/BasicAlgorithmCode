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

#define MAXSIZE 100 /* �洢�ռ��ʼ������ */

typedef int Status;		/* Status�Ǻ���������,��ֵ�Ǻ������״̬���룬��OK�� */

typedef char TElemType;
TElemType Nil = ' '; /* �ַ����Կո��Ϊ�� */

Status visit(TElemType e)
{
	printf("%c ", e);
	return OK;
}

/* ���ڹ��������********************************** */
int index = 1;
typedef char String[24]; /*  0�ŵ�Ԫ��Ŵ��ĳ��� */
String str;
////
typedef struct BiTNode  /* ���ṹ */
{
	TElemType data;		/* ������� */
	struct BiTNode *lchild, *rchild; /* ���Һ���ָ�� */

}BiTNode, *BiTree;    //*BiTree����˼�Ǹ� struct node*���˸���������BiTree����BiTreeΪָ��ڵ��ָ�롣

/////
Status InitBiTree(BiTree *T)
{
	*T = NULL;
	return OK;
}

/* ��ǰ������������н���ֵ��һ���ַ��� */
/* #��ʾ������������������ʾ������T�� */
void CreateBiTree(BiTree *T)// BiTree Ϊָ����struct BiTNode ��ָ�룬���TΪָ��ָ���ָ��		
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
		(*T)->data = ch; /* ���ɸ���� */
		CreateBiTree(&(*T)->lchild); /* ���������� */ //����TΪָ��ָ���ָ�룬����(*T)Ϊָ�����ָ��
		CreateBiTree(&(*T)->rchild); /* ���������� */
	}
}
//���߿������´���һ��������
void createBiTree(BiTree &T) //&����˼�Ǵ������ڵ�ָ������ã������ڵȼ��� BiTreeNode* &T,Ŀ�����ô��ݽ�����ָ�뷢���ı�
{
	char ch;
	scanf("%c", &ch);
	if ('#' == ch)             //������#ʱ�������ĸ��ڵ�ΪNULL���Ӷ������÷�֧�ĵݹ�
		T = NULL;
	else
	{
		T = new BiTNode;
		T->data = ch;
		createBiTree(T->lchild);
		createBiTree(T->rchild);
	}
}
