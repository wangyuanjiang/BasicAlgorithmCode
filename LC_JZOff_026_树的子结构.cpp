#include "JZOff.h"

//全是递归思想
class Solution {
public:
	bool isSubStructure(TreeNode* pRoot1, TreeNode* pRoot2)
	{
		bool res = false;
		//当Tree1和Tree2都不为零的时候，才进行比较。否则直接返回false
		if (pRoot1 != nullptr && pRoot2 != nullptr) {
			// if(pRoot1 == NULL || pRoot2==NULL) // 这样也行，因为约定空树不是任意一个树的子结构
			   // return false;

			  //如果找到了对应Tree2的根节点的点，调用是否包含函数
			if (pRoot1->val == pRoot2->val)
				res = DoseTree1HasTree2(pRoot1, pRoot2);
			//如果还没找到，继续去root的左子树寻找，去判断时候包含Tree2
			if (!res)
				res = isSubStructure(pRoot1->left, pRoot2);
			//如果还找不到，继续去root的右子树寻找，去判断时候包含Tree2
			if (!res)
				res = isSubStructure(pRoot1->right, pRoot2);
		}
		return res;
	}
	bool  DoseTree1HasTree2(TreeNode* pRoot1, TreeNode* pRoot2)
	{
		if (pRoot2 == nullptr)  // 如果交换这两个if语句会得不到正确的结果，当pRoot1 和pRoot2 同时为空时，应该先判断proot2
			return true;	// //如果Tree2已经遍历完了都能对应的上，返回true

		if (pRoot1 == nullptr)	//如果Tree2还没有遍历完，Tree1却遍历完了。返回false
			return false;

		if (pRoot1->val != pRoot2->val)	//如果其中有一个点没有对应上，返回false	
			return false;
		//如果根节点对应的上，那么就分别去子节点里面匹配
		return  DoseTree1HasTree2(pRoot1->left, pRoot2->left) && DoseTree1HasTree2(pRoot1->right, pRoot2->right);
	}
};
