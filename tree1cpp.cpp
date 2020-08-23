#include <iostream>

#include <stack>
#include <vector>
#include <queue>
using namespace std;
struct TreeNode
{
	int val;
	TreeNode *left;
	TreeNode *right;
	//TreeNode(int x) :val(x), left(NULL), right(NULL);
};

vector<int> perOrder(TreeNode* root) {
	if (!root) return;
	vector<int> ans;
	stack<TreeNode*>s;
	while (root || !s.empty()) {
		while (root)
		{
			ans.push_back(root->val);
			s.push(root);
			root = root->left;
		}

		root = s.top();
		s.pop();
		root = root->right;
	}
	return ans;
}
vector<int>midOrder(TreeNode* root) {
	if (!root) return;
	vector<int> ans;
	stack<TreeNode*>s;
	while (root || !s.empty()) {
		while (root)
		{
			s.push(root);
			root = root->left;
		}
		root = s.top();
		s.pop();
		ans.push_back(root ->val);
		root = root->right;
	}
	return ans;
}

vector<int>posOrder(TreeNode* root) {
	if (!root) return;
	vector<int> ans;
	stack<TreeNode*>s;
	s.push(root);
	s.push(root);
	while (!s.empty())
	{

		root = s.top();
		s.pop();
		if (!s.empty()&&root == s.top()) {
			if (root->right) {
				s.push(root->right);
				s.push(root->right);
			}
			if (root->left) {
				s.push(root->left);
				s.push(root->left);
			}
		}
		else
			ans.push_back(root->val);
	}
	return ans;
}

void perOrder_recursion(TreeNode* root){
	if (!root)
		return;
	printf("%d",root->val);
	perOrder_recursion(root->left);
	perOrder_recursion(root->right);

}
void midOrder_recursion(TreeNode* root) {
	if (!root)
		return;
	midOrder_recursion(root->left);
	printf("%d", root->val);
	midOrder_recursion(root->right);
}
void posOrder_recursion(TreeNode* root) {
	if (!root)
		return;
	posOrder_recursion(root->left);
	posOrder_recursion(root->right);
	printf("%d", root->val);
}

vector<vector<int>> levelOreder_recurion(TreeNode* root) {
	vector<vector<int>>ans;
	 helper(root, 0, ans);
	 return ans;
	
}
void helper(TreeNode* root, int depth, vector<vector<int>>& ans) {
	vector<vector<int>>ans;
	if (!root)
		return;
	if (depth >= ans.size())
		ans.push_back(vector<int>{});
	ans[depth].push_back(root->val);
	helper(root->left, depth + 1, ans);
	helper(root->right, depth + 1, ans);
}

vector<vector<int>>levelOrder(TreeNode* root) {
	vector<vector<int>> ans;
	if (root) return ans;
	queue<TreeNode*> cur;
	queue<TreeNode*> nex;
	//cur.push(root);
	ans.push_back(vector<int>(1, root->val));
	cur.push(root);
	while (!cur.empty()) {
		root = cur.front();
		cur.pop();
		if (root->left)  nex.push(root->left);
		if (root->right) nex.push(root->right);
		if (cur.empty()) {
			vector<int>tem;
			while (!nex.empty()) {
				root = nex.front();
				nex.pop();
				cur.push(root);

				tem.push_back(root->val);
			}
			ans.push_back(tem);
		}
	}
	return ans;
}
