// Tree.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>

#include <stack>
#include <vector>
using namespace std;
struct TreeNode
{
	int val;
	TreeNode *left;
	TreeNode *right;
	//TreeNode(int x) :val(x), left(NULL), right(NULL);
};
void preorder(TreeNode* root) {
	if (root == NULL)
		std:: cout << "The tree is empty!" <<std:: endl;
	std::stack< TreeNode *> s;
			while (root || !s.empty()) {
			while (root) {
				std::cout << root->val << " ";
				s.push(root);
				root = root->left;
			}
			root = s.top();
			s.pop();
			root = root->right;
		}
	}

void midorder2(TreeNode* root) {
	if (root)
		cout << "empty!" << endl;
	stack<TreeNode* > s;
	while (root || !s.empty()) {

		while (root) {
			s.push(root);
			root = root->left;
		}
		root = s.top();
		s.pop();
		cout << root->val;
		root = root->right;
	}
}

//中序遍历
typedef TreeNode BTNode;
void midorderWithoutRecursion1(BTNode* root)
{
	//空树
	if (root == NULL)
		return;
	//树非空
	BTNode* p = root;
	stack<BTNode*> s;
	while (!s.empty() || p)//因为有迭代，当输出最后一个结点的值时，s已经为空，而p=p->right也为空，因此不会出现操作空栈的情况；
	{
		//一直遍历到左子树最下边，边遍历边保存根节点到栈中
		while (p)
		{
			s.push(p);
			p = p->left;
		}
		//当p为空时，说明已经到达左子树最下边，这时需要出栈了
		if (!s.empty())
		{
			p = s.top();
			s.pop();
			cout  << p->val<<" ";//
			//进入右子树，开始新的一轮左子树遍历(这是递归的自我实现)
			p = p->right;
		}
	}
}

//后序遍历
vector<int> postOrder(TreeNode *root)
{
	vector<int> res;
	if (root == NULL) return res;

	TreeNode *p = root;
	stack<TreeNode *> sta;
	sta.push(p);
	sta.push(p);
	while (!sta.empty())//和前序和中序相比，输出最后一个结点的值时，s也已经为空，而由于没有迭代，root不为空，
	                    //因此如果条件语句改为!s.empty() || p；则会在输出最后一个结点的值时，继续操作空栈，引发错误。
	{
		p = sta.top();
		sta.pop();
		if (!sta.empty() && p == sta.top())//执行sta.pop()之后sta.top()已经改变；
		{
			if (p->right)  sta.push(p->right), sta.push(p->right); 
			if (p->left)  sta.push(p->left), sta.push(p->left); 
		}
		else
			res.push_back(p->val);
	}

	return res;
}

//对于每个节点，都压入两遍，在循环体中，每次弹出一个节点赋给p，如果p仍然等于栈的头结点，
//说明p的孩子们还没有被操作过，应该把它的孩子们加入栈中，否则，访问p。
//也就是说，第一次弹出，将p的孩子压入栈中，第二次弹出，访问p。


//层次遍历
vector<vector<int>> levelOrder(TreeNode* root) {
	vector<vector<int>> ans;
	pre(root, 0, ans);
	return ans;
}

void pre(TreeNode *root, int depth, vector<vector<int>> &ans) {
	if (!root) return;
	if (depth >= ans.size())//说明需要扩充
		ans.push_back(vector<int> {});
	ans[depth].push_back(root->val);
	pre(root->left, depth + 1, ans);
	pre(root->right, depth + 1, ans);
}
