
#include "JZOff.h"

class solution
{
public:
	int maxDepth(TreeNode* root) {

		if (root == nullptr)
			return 0;

		int nleft = maxDepth(root->left) + 1;

		int nright = maxDepth(root->right) + 1;


		return  nleft > nright ? nleft : nright;

	}

};