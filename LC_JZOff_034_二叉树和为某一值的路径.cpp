#include "JZOff.h"

class Solution {
public:
	vector<vector<int>> pathSum(TreeNode* root, int k) {

		if (root == NULL) return res;
		backtrack(root, k);

		return res;

	}

	void backtrack(TreeNode* root, int k) {

		if (root == NULL) return;	//一定要注意递归出口

		temp.push_back(root->val);
		sum += root->val;
	  
		if (root->left == NULL && root->right == NULL && sum == k)
			res.push_back(temp);

		backtrack(root->left, k );
		backtrack(root->right, k);

		sum -= root->val;
		temp.pop_back();

	}




private:
	vector<vector<int>> res;
	vector<int> temp;
	int sum;


};