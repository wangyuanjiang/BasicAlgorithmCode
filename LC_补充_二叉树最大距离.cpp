
#include "JZOff.h"

int HeightOfBinaryTree(TreeNode*pNode, int&nMaxDistance) {
	if (pNode == NULL)
		return 0;   //空节点的高度为-1
	//递归
	int nHeightOfLeftTree = HeightOfBinaryTree(pNode->left, nMaxDistance) + 1;   //左子树的的高度加1
	int nHeightOfRightTree = HeightOfBinaryTree(pNode->right, nMaxDistance) + 1;   //右子树的高度加1
	int nDistance = nHeightOfLeftTree + nHeightOfRightTree;    //距离等于左子树的高度加上右子树的高度+2
	nMaxDistance = nMaxDistance > nDistance ? nMaxDistance : nDistance;            //得到距离的最大值
	return nHeightOfLeftTree > nHeightOfRightTree ? nHeightOfLeftTree : nHeightOfRightTree;
}

//---------------------------以下来自 编程之美------------------------------

struct NODE
{
	NODE* pLeft;        // 左子树
	NODE* pRight;       // 右子树
	int nMaxLeft;       // 左子树中的最长距离
	int nMaxRight;      // 右子树中的最长距离
	char chValue;       // 该节点的值
};

int nMaxLen = 0;

// 寻找树中最长的两段距离
void FindMaxLen(NODE* pRoot)
{
	// 遍历到叶子节点，返回
	if (pRoot == NULL)
	{
		return;
	}

	// 如果左子树为空，那么该节点的左边最长距离为0
	if (pRoot->pLeft == NULL)
	{
		pRoot->nMaxLeft = 0;
	}

	// 如果右子树为空，那么该节点的右边最长距离为0
	if (pRoot->pRight == NULL)
	{
		pRoot->nMaxRight = 0;
	}

	// 如果左子树不为空，递归寻找左子树最长距离
	if (pRoot->pLeft != NULL)
	{
		FindMaxLen(pRoot->pLeft);
	}

	// 如果右子树不为空，递归寻找右子树最长距离
	if (pRoot->pRight != NULL)
	{
		FindMaxLen(pRoot->pRight);
	}

	// 计算左子树最长节点距离
	if (pRoot->pLeft != NULL)
	{
		pRoot->nMaxLeft = ((pRoot->pLeft->nMaxLeft > pRoot->pLeft->nMaxRight) ? pRoot->pLeft->nMaxLeft : pRoot->pLeft->nMaxRight) + 1;
	}

	// 计算右子树最长节点距离
	if (pRoot->pRight != NULL)
	{
		pRoot->nMaxRight = ((pRoot->pRight->nMaxLeft > pRoot->pRight->nMaxRight) ? pRoot->pRight->nMaxLeft : pRoot->pRight->nMaxRight) + 1;
	}

	// 更新最长距离
	if (pRoot->nMaxLeft + pRoot->nMaxRight > nMaxLen)
	{
		nMaxLen = pRoot->nMaxLeft + pRoot->nMaxRight;
	}
}

