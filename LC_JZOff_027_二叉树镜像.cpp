#include "JZOff.h"

/*�����һ������������һ�����������ú���������ľ���*/

class Solution {
public:
	TreeNode* mirrorTree(TreeNode* root) {
				
		mirrorTree2(root);
		return root;

	}
	void mirrorTree2(TreeNode* root) {	//����ǰ������������Ĺ����У����ĳ���ڵ����ӽ��ͽ������������ӽ�㣻
		if (root == NULL) return;
		if (root->left == NULL && root->right == NULL)    return;

		TreeNode* p = root->left;
		root->left = root->right;
		root->right = p;

		if (root->left)
			mirrorTree(root->left);

		if (root->right)
			mirrorTree(root->right);
	}

	//��ǰ�������������һ���������������Ĳ�����
};