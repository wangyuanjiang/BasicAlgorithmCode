
#include "JZOff.h"

class Solution {  //别人法递归分治
public:
	TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
		//递归分治
		return recursionBuild(preorder.begin(), preorder.end(), inorder.begin(), inorder.end());
	}

	//递归分治
	TreeNode* recursionBuild(vector<int>::iterator preBegin, vector<int>::iterator preEnd, vector<int>::iterator inBegin, vector<int>::iterator inEnd)
	{
		if (inEnd == inBegin) return NULL;	//不加这句会报错
		//二叉树的前序遍历中的第一位一定是根节点
		TreeNode* cur = new TreeNode(*preBegin);
		//找到根节点在中序遍历中的位置，中序遍历之前的节点都是左子树节点，之后都是右子树节点
		auto root = find(inBegin, inEnd, *preBegin); //如果找到返回迭代器
		cur->left = recursionBuild(preBegin + 1, preBegin + (root - inBegin) + 1, inBegin, root);
		cur->right = recursionBuild(preBegin + 1 + (root - inBegin), preEnd, root + 1, inEnd);
		return cur;
	}//中序系列需要中部跳过root ，所以是root， root+1，而不是root， root
	//前序系列在开头跳过root，所以是preBegin + 1
};


class Solution {  //按照书敲的
public:
	TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {

		if (preorder.empty() || inorder.empty())
			return NULL;
		
		int a[preorder.size()];
		int b[inorder.size()];
		memcpy(a, &preorder[0], preorder.size() * sizeof(preorder[0]));
		memcpy(b, &inorder[0], inorder.size() * sizeof(inorder[0]));
		int* pre;
		int* ino;
		pre = a;
		ino = b;
		int len = preorder.size();
		return Constuct(pre, pre + len - 1, ino, ino + len - 1);

	}

	TreeNode* Constuct(
		int* startPer,
		int* endPer,
		int* startIno,
		int* endIno
	)
	{
		int rootValue = startPer[0];
		TreeNode* root = new TreeNode(rootValue);
		root->left = root->right = NULL;

		if (startPer == endPer)
		{
			if (startIno == endIno && *startPer == *startIno)
				return root;
			else
				throw "Invail Input";
		}

		int* rootIno = startIno;
		while (rootIno <= endIno && *rootIno != rootValue)
			rootIno++;
		if (rootIno == endIno && rootValue != *rootIno)
			throw "Invail Input";

		int leftLen = rootIno - startIno;
		int *leftPerEnd = startPer + leftLen;

		if (leftLen > 0)
		{
			root->left = Constuct(startPer + 1, leftPerEnd, startIno, rootIno - 1);
		}

		if (endIno - rootIno > 0)
		{
			root->right = Constuct(leftPerEnd + 1, endPer, rootIno + 1, endIno);
		}

		return root;

	}
};
