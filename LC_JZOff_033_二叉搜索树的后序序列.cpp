
#include "JZOff.h"


/*思路：
已知条件： 后序序列最后一个值为root；二叉搜索树左子树的值都比root小，右子树的值都比root大。

步骤：

1.确定根节点root；
2.遍历序列（除去root结点），找到第一个大于root的位置，则该位置左边为左子树，右边为右子树；
3.遍历右子树，若发现有小于root的值，则直接返回false；
4.分别判断左子树和右子树是否仍是二叉搜索树（即递归步骤1、2、3）。

*/
class Solution {
public:
	bool verifyPostorder(vector<int>& postorder) {

		if (postorder.empty()) return true;
		int len = postorder.size();

		return isPostorder(postorder, 0, len);

	}
	bool isPostorder(vector<int>& postorder, int begin, int len) {

		if (begin > len) return true;	//不加这句话会超时
		int root = postorder[len - 1];
		int i = begin;
		for (; i < len - 1; i++) {
			if (postorder[i] > root)
				break;
		}
		int j = i;
		for (; j < len - 1; j++)
		{
			if (postorder[j] < root)
				return false;
		}

		bool left = true;
		if (i > 0)
			left = isPostorder(postorder, 0, i);

		bool right = true;
		if (i < len - 1)
			right = isPostorder(postorder, i, len - i - 1);

		return left && right;
	}
};