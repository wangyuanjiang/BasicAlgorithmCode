#include <iostream>
#include <vector>
#include <numeric>
#include <limits>
#include<string>
#include<stack>
using namespace std;


/*������������������ʵ����ĿҪ��Ĺ���
��Ȼ����Ҳ���Բ������������ģ����������ȫ�����Լ����뷨�� ^-^
******************************��ʼд����******************************/
typedef char TElemType;

typedef struct BiTNode  /* ���ṹ */
{
	TElemType data;		/* ������� */
	struct BiTNode *lchild, *rchild; /* ���Һ���ָ�� */

}BiTNode, *BiTree;


//auto it = input.begin()
void CreateBiTree(string::iterator it, int len, BiTree &T)// BiTree Ϊָ����struct BiTNode ��ָ�룬���TΪָ��ָ���ָ��		
{
	
	while(len >0) {
		T = new BiTNode;
			if (isdigit(*it))
				T->data = *it;
			    len--;
				it++;
			if (*it == '(')
			{
				
				CreateBiTree(it,len, T->lchild);
				CreateBiTree(it, len, T->rchild);
			}
			else
				continue;
		}
	
}
/*
string InOrderTraverse(BiTree T)
{
	string res;
	if (T == NULL)
		return res;

	InOrderTraverse(T->lchild); // ������������� 
	//printf("%c",T->data);  ��ʾ������ݣ����Ը���Ϊ�����Խ����� 
	//res.push_back(T->data);
	//InOrderTraverse(T->rchild);  ���������������� 
} */

typedef BiTNode BTNode;
string  midorderWithoutRecursion1(BTNode* root)
{
	string res;
	//����
	if (root == NULL)
		return res;
	//���ǿ�
	BTNode* p = root;
	stack<BTNode*> s;
	while (!s.empty() || p)//��Ϊ�е�������������һ������ֵʱ��s�Ѿ�Ϊ�գ���p=p->rightҲΪ�գ���˲�����ֲ�����ջ�������
	{
		//һֱ���������������±ߣ��߱����߱�����ڵ㵽ջ��
		while (p)
		{
			s.push(p);
			p = p->lchild;
		}
		//��pΪ��ʱ��˵���Ѿ��������������±ߣ���ʱ��Ҫ��ջ��
		if (!s.empty())
		{
			p = s.top();
			s.pop();
			res.push_back(p->data);
			//��������������ʼ�µ�һ������������(���ǵݹ������ʵ��)
			p = p->rchild;
		}
	}
	return res;
}

string solution(string input) {

	BiTree T;
	int len = input.size();
	auto it = input.begin();

	CreateBiTree(it, len, T);
	string res = midorderWithoutRecursion1(T);
		return res;
}


/******************************����д����******************************/


int main_906() {
	string res;

	string _input;
	getline(cin, _input);

	res = solution(_input);
	cout << res << endl;

	getchar();
	return 0;

}

