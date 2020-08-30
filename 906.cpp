#include <iostream>
#include <vector>
#include <numeric>
#include <limits>
#include<string>
#include<stack>
using namespace std;


/*请完成下面这个函数，实现题目要求的功能
当然，你也可以不按照下面这个模板来作答，完全按照自己的想法来 ^-^
******************************开始写代码******************************/
typedef char TElemType;

typedef struct BiTNode  /* 结点结构 */
{
	TElemType data;		/* 结点数据 */
	struct BiTNode *lchild, *rchild; /* 左右孩子指针 */

}BiTNode, *BiTree;


//auto it = input.begin()
void CreateBiTree(string::iterator it, int len, BiTree &T)// BiTree 为指向结点struct BiTNode 的指针，因此T为指向指针的指针		
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

	InOrderTraverse(T->lchild); // 中序遍历左子树 
	//printf("%c",T->data);  显示结点数据，可以更改为其它对结点操作 
	//res.push_back(T->data);
	//InOrderTraverse(T->rchild);  最后中序遍历右子树 
} */

typedef BiTNode BTNode;
string  midorderWithoutRecursion1(BTNode* root)
{
	string res;
	//空树
	if (root == NULL)
		return res;
	//树非空
	BTNode* p = root;
	stack<BTNode*> s;
	while (!s.empty() || p)//因为有迭代，当输出最后一个结点的值时，s已经为空，而p=p->right也为空，因此不会出现操作空栈的情况；
	{
		//一直遍历到左子树最下边，边遍历边保存根节点到栈中
		while (p)
		{
			s.push(p);
			p = p->lchild;
		}
		//当p为空时，说明已经到达左子树最下边，这时需要出栈了
		if (!s.empty())
		{
			p = s.top();
			s.pop();
			res.push_back(p->data);
			//进入右子树，开始新的一轮左子树遍历(这是递归的自我实现)
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


/******************************结束写代码******************************/


int main_906() {
	string res;

	string _input;
	getline(cin, _input);

	res = solution(_input);
	cout << res << endl;

	getchar();
	return 0;

}

