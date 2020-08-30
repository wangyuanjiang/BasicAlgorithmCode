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



typedef struct BiTNode  /* ���ṹ */
{
	TElemType data;		/* ������� */
	struct BiTNode *lchild, *rchild; /* ���Һ���ָ�� */

}BiTNode, *BiTree;

bool InitBiTree(BiTree *T)
{
	*T = NULL;
	return true;
}

void CreateBiTree(BiTree *T)// BiTree Ϊָ����struct BiTNode ��ָ�룬���TΪָ��ָ���ָ��		
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
			(*T)->data = ch; /* ���ɸ���� */
			CreateBiTree(&(*T)->lchild); /* ���������� */ //����TΪָ��ָ���ָ�룬����(*T)Ϊָ�����ָ��
			CreateBiTree(&(*T)->rchild); /* ���������� */
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

/* ��ʼ����: ������T���� */
/* �������: ����ݹ����T */
void InOrderTraverse(BiTree T)
{
	if (T == NULL)
		return;
	InOrderTraverse(T->lchild); /* ������������� */
	printf("%c", T->data);/* ��ʾ������ݣ����Ը���Ϊ�����Խ����� */
	InOrderTraverse(T->rchild); /* ���������������� */
}

/* ��ʼ����: ������T���� */
/* �������: ����ݹ����T */
void PostOrderTraverse(BiTree T)
{
	if (T == NULL)
		return;
	PostOrderTraverse(T->lchild); /* �Ⱥ������������  */
	PostOrderTraverse(T->rchild); /* �ٺ������������  */
	printf("%c", T->data);/* ��ʾ������ݣ����Ը���Ϊ�����Խ����� */
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

	//printf("\nǰ�����������:");
	//PreOrderTraverse(T);
	//printf("\n�������������:");
	//InOrderTraverse(T);
	printf("\n�������������:");
	PostOrderTraverse(T);
	

	system("pause");
	return 0;
}