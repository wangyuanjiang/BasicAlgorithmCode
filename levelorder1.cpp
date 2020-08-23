#include<iostream>
#include<vector>

using namespace std;

struct TreeNode {
	int val;
	TreeNode *lift,*right;
	
};
vector<vector<int>> levelOrder(TreeNode* root) {
	vector<vector<int>> ans;
	 help(root, ans,  0);
}

void help(TreeNode* root, vector<vector<int>>& ans, size_t deth) {
	if (root = NULL)
		return ;
	if (deth >= ans.size())
		ans.push_back(vector<int> {});
	ans[deth].push_back(root->val);
	help(root->lift, ans, deth + 1);
	help(root->right, ans, deth + 1);
}