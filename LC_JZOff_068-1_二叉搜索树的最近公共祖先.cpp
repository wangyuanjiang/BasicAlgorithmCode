#include "JZOff.h"
/*利用二叉搜索树的特征，即根节点左子树的节点的值都小于根节点，根节点右子树的节点的值都大于根节点。
从根节点往下遍历，若节点值大于两目标节点，则两目标节点均在该点左子树，若节点值小于两目标节点，则两目标节点均在该点右子树。
第一个数值在两个目标节点之间的节点即为结果。

*/
class Solution {
public:
	TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {

		if (root == NULL || p == NULL || q == NULL)
		{
			return NULL;
		}

		while (root) {

			if (root->val > p->val && root->val > q->val)     root = root->left;
			else if (root->val < p->val && root->val < q->val)   root = root->right;

			else
				break;

		}

		return root;
	}
};
