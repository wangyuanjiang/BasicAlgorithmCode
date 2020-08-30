#include "JZOff.h"
/*���ö����������������������ڵ��������Ľڵ��ֵ��С�ڸ��ڵ㣬���ڵ��������Ľڵ��ֵ�����ڸ��ڵ㡣
�Ӹ��ڵ����±��������ڵ�ֵ������Ŀ��ڵ㣬����Ŀ��ڵ���ڸõ������������ڵ�ֵС����Ŀ��ڵ㣬����Ŀ��ڵ���ڸõ���������
��һ����ֵ������Ŀ��ڵ�֮��Ľڵ㼴Ϊ�����

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
