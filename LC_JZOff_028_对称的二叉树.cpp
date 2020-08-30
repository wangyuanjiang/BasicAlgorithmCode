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

class Solution { //���취���ȸ��ƣ������� ���жϾ����ԭʼ���Ƿ����
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
		
		// TreeNode* p = root;		//���󣡣�����������
		
		if (root == nullptr) return root;
		TreeNode* p = new TreeNode(root->val); //���ƹ�������Ҫ����new����������������������

		p->left = copyTree(root->left);
		p->right = copyTree(root->right);

		return p;
	}

	void mirrorTree2(TreeNode* root) {	//����ǰ������������Ĺ����У����ĳ���ڵ����ӽ��ͽ������������ӽ�㣻
		
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


class Solution {	//ǰ������ͶԳ�ǰ�������
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