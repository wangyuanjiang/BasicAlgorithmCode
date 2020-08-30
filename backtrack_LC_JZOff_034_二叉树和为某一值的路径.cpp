
#include<iostream>
#include <vector>
using namespace std;

struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
		val(x), left(NULL), right(NULL) {
	}
} *BiTree;

class Solution {
public:
	vector<vector<int>> pathSum(TreeNode* root, int k) {

		vector<vector<int>> vec;
		vector<int> tem;
		int sum = 0;
		backtrack(root, k, vec, tem, sum);

		return vec;
		
	}

	void backtrack(TreeNode* root, int k, vector<vector<int> >&vec, vector<int>& tem, int& sum)
	{
		if (!root)	return;

		sum += root->val;	//ох╪с
		tem.push_back(root->val);

		if (root->left == nullptr && root->right == nullptr && sum == k)//тыеп╤о
			vec.push_back(tem);
				
		backtrack(root->left, k, vec, tem, sum);
		backtrack(root->right, k, vec, tem, sum);

		sum -= root->val;
		tem.pop_back();


	}
};