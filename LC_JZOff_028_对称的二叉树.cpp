#include "JZOff.h"

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution { //笨办法，先复制，再求镜像， 再判断镜像和原始的是否相等
public:
	bool isSymmetric(TreeNode* root) {
		if (root == nullptr)		return true;

		if (root->left == nullptr && root->right == nullptr)	return true;

		TreeNode* p = copyTree(root);
		mirrorTree2(p);
		return Tree1EqualTree2(p, root);
	}

	TreeNode* copyTree(TreeNode* root)
	{
		
		// TreeNode* p = root;		//错误！！！！！！！
		
		if (root == nullptr) return root;
		TreeNode* p = new TreeNode(root->val); //复制过程中需要不断new，！！！！！！！！！！

		p->left = copyTree(root->left);
		p->right = copyTree(root->right);

		return p;
	}

	void mirrorTree2(TreeNode* root) {	//求镜像，前序遍历，遍历的过程中，如果某个节点有子结点就交换它的左右子结点；
		
		if (root == NULL) return;
		if (root->left == NULL && root->right == NULL)    return;

		TreeNode* p = root->left;
		root->left = root->right;
		root->right = p;

		if (root->left)
			mirrorTree2(root->left);

		if (root->right)
			mirrorTree2(root->right);
	}

	bool Tree1EqualTree2(TreeNode* p1, TreeNode* p2)
	{
		if (p1 == nullptr && p2 == nullptr)	return true;
		if (p1 == nullptr || p2 == nullptr)	return false;
		if (p1->val != p2->val)	return false;

		return (Tree1EqualTree2(p1->left, p2->left) && Tree1EqualTree2(p1->right, p2->right));

	}
};


class Solution {	//前序遍历和对称前序遍历。
public:
	bool isSymmetric(TreeNode* root) {
		return isSymmetric(root, root);
	}

	bool isSymmetric(TreeNode* p1, TreeNode* p2)
	{
		if (p1 == NULL && p2 == NULL)    return true;

		if (p1 == NULL || p2 == NULL)    return false;

		if (p1->val != p2->val)    return false;

		return(isSymmetric(p1->left, p2->right) && isSymmetric(p1->right, p2->left));
	}

};