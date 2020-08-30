#include "JZOff.h"


//自己写的， 从根结点开始寻找p,q ，如果p,q同时在root的右子树，则在root的右子树继续寻找，如果p，q同时在root的左子树，
//则在root的左子树继续寻找，否则返回root；
class Solution {
public:
	TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
		if (root == NULL ||root ==p || root == q)
			return root;
		while (root) {
			if (findTree(root->left, p) && findTree(root->left, q))
				root = root->left;

			else if (findTree(root->right, p) && findTree(root->right, q))
				root = root->right;
			else
				break;
		}

		return root;

	}

	bool findTree(TreeNode* root, TreeNode* p) {


		if (root == NULL)    return false;	//root 为空说明没找到

		bool res = false;	

		if (root->val == p->val)		//值相等，说明找到了
			res = true;

		if (!res)
			res = findTree(root->left, p);	//左子树递归find
		if (!res)
			res = findTree(root->right, p);	//右子树递归find

		return res;
	}
};

/*因为lowestCommonAncestor(root, p, q)的功能是找出以root为根节点的两个节点p和q的最近公共祖先，
所以递归体分三种情况讨论：

如果p和q分别是root的左右节点，那么root就是我们要找的最近公共祖先
如果p和q都是root的左节点，那么返回lowestCommonAncestor(root->left,p,q)
如果p和q都是root的右节点，那么返回lowestCommonAncestor(root->right,p,q)

边界条件讨论：!!!!!!!!!!!!!!!!!
如果root是null，则说明我们已经找到最底了，返回null表示没找到
如果root与p相等或者与q相等，则返回root
如果左子树没找到，递归函数返回null，证明p和q同在root的右侧，那么最终的公共祖先就是右子树找到的结点
如果右子树没找到，递归函数返回null，证明p和q同在root的左侧，那么最终的公共祖先就是左子树找到的结点*/

class Solution {	//别人的递归

public:
	TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
		// 若root包含p 返回p
		// 若root包含q 返回q
		// 若root都不包含 返回NULL
		// 若以root的子树中包含p和q 返回root(最近公共祖先)
		if (!root || root == p || root == q) return root;

		auto left =  lowestCommonAncestor(root->left, p, q);
		auto right = lowestCommonAncestor(root->right, p, q);

		if (!left) return right;
		if (!right) return left;

		return root;
	}
};

