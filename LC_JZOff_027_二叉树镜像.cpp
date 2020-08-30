#include "JZOff.h"

/*请完成一个函数，输入一个二叉树，该函数输出它的镜像*/

class Solution {
public:
	TreeNode* mirrorTree(TreeNode* root) {
				
		mirrorTree2(root);
		return root;

	}
	void mirrorTree2(TreeNode* root) {	//求镜像，前序遍历，遍历的过程中，如果某个节点有子结点就交换它的左右子结点；
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

	//比前序遍历仅仅多了一个交换左右子树的操作；
};