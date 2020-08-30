#include <iostream>
#include <vector>
#include <numeric>
#include <limits>
#include<string>
#include<stack>
using namespace std;

string str906;
int index906 = 0;
typedef char TElemType;
TElemType Nil = ' ';
typedef int Status;



typedef struct BiTNode  /* 结点结构 */
{
	TElemType data;		/* 结点数据 */
	struct BiTNode *lchild, *rchild; /* 左右孩子指针 */

}BiTNode, *BiTree;

bool InitBiTree(BiTree *T)
{
	*T = NULL;
	return true;
}

void CreateBiTree(BiTree *T)// BiTree 为指向结点struct BiTNode 的指针，因此T为指向指针的指针		
{
	TElemType ch;

	/* scanf("%c",&ch); */
	if (index906 < str906.size())
	{
		ch = str906[index906++];
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
}

void PreOrderTraverse(BiTree T)
{
	if (T == NULL)
		return;
	printf("%c", T->data);/* 显示结点数据，可以更改为其它对结点操作 */
	PreOrderTraverse(T->lchild); /* 再先序遍历左子树 */
	PreOrderTraverse(T->rchild); /* 最后先序遍历右子树 */
}

/* 初始条件: 二叉树T存在 */
/* 操作结果: 中序递归遍历T */
void InOrderTraverse(BiTree T)
{
	if (T == NULL)
		return;
	InOrderTraverse(T->lchild); /* 中序遍历左子树 */
	printf("%c", T->data);/* 显示结点数据，可以更改为其它对结点操作 */
	InOrderTraverse(T->rchild); /* 最后中序遍历右子树 */
}

/* 初始条件: 二叉树T存在 */
/* 操作结果: 后序递归遍历T */
void PostOrderTraverse(BiTree T)
{
	if (T == NULL)
		return;
	PostOrderTraverse(T->lchild); /* 先后序遍历左子树  */
	PostOrderTraverse(T->rchild); /* 再后序遍历右子树  */
	printf("%c", T->data);/* 显示结点数据，可以更改为其它对结点操作 */
}

int main_9061()
{
	string str1,str2;
	cout << "please entyr str" << endl;
	cin >> str1;
	for (int i = 1; i <= str1.size(); i++)
	{
		if (str1[i - 1] == '(' && str1[i] == ',') 
			str2.push_back('#');
			
		
		else if (str1[i - 1] == ',' && str1[i] == ')')
			str2.push_back('#');
		else
			str2.push_back(str1[i - 1]);
	}

	for (int i = 0; i < str2.size(); i++)
	{
		if (str2[i] == ')' || str2[i] == '(' || str2[i] == ',')
			continue;
		else
		{
			str906.push_back(str2[i]);
		}
	}

	cout << str2 << endl;
	cout << str906 << endl;

	BiTree T;

	InitBiTree(&T);
	CreateBiTree(&T);

	//printf("\n前序遍历二叉树:");
	//PreOrderTraverse(T);
	//printf("\n中序遍历二叉树:");
	//InOrderTraverse(T);
	printf("\n后序遍历二叉树:");
	PostOrderTraverse(T);
	

	system("pause");
	return 0;
}