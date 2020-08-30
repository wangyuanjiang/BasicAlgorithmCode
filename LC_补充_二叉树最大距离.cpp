
#include "JZOff.h"

int HeightOfBinaryTree(TreeNode*pNode, int&nMaxDistance) {
	if (pNode == NULL)
		return 0;   //�սڵ�ĸ߶�Ϊ-1
	//�ݹ�
	int nHeightOfLeftTree = HeightOfBinaryTree(pNode->left, nMaxDistance) + 1;   //�������ĵĸ߶ȼ�1
	int nHeightOfRightTree = HeightOfBinaryTree(pNode->right, nMaxDistance) + 1;   //�������ĸ߶ȼ�1
	int nDistance = nHeightOfLeftTree + nHeightOfRightTree;    //��������������ĸ߶ȼ����������ĸ߶�+2
	nMaxDistance = nMaxDistance > nDistance ? nMaxDistance : nDistance;            //�õ���������ֵ
	return nHeightOfLeftTree > nHeightOfRightTree ? nHeightOfLeftTree : nHeightOfRightTree;
}

//---------------------------�������� ���֮��------------------------------

struct NODE
{
	NODE* pLeft;        // ������
	NODE* pRight;       // ������
	int nMaxLeft;       // �������е������
	int nMaxRight;      // �������е������
	char chValue;       // �ýڵ��ֵ
};

int nMaxLen = 0;

// Ѱ������������ξ���
void FindMaxLen(NODE* pRoot)
{
	// ������Ҷ�ӽڵ㣬����
	if (pRoot == NULL)
	{
		return;
	}

	// ���������Ϊ�գ���ô�ýڵ����������Ϊ0
	if (pRoot->pLeft == NULL)
	{
		pRoot->nMaxLeft = 0;
	}

	// ���������Ϊ�գ���ô�ýڵ���ұ������Ϊ0
	if (pRoot->pRight == NULL)
	{
		pRoot->nMaxRight = 0;
	}

	// �����������Ϊ�գ��ݹ�Ѱ�������������
	if (pRoot->pLeft != NULL)
	{
		FindMaxLen(pRoot->pLeft);
	}

	// �����������Ϊ�գ��ݹ�Ѱ�������������
	if (pRoot->pRight != NULL)
	{
		FindMaxLen(pRoot->pRight);
	}

	// ������������ڵ����
	if (pRoot->pLeft != NULL)
	{
		pRoot->nMaxLeft = ((pRoot->pLeft->nMaxLeft > pRoot->pLeft->nMaxRight) ? pRoot->pLeft->nMaxLeft : pRoot->pLeft->nMaxRight) + 1;
	}

	// ������������ڵ����
	if (pRoot->pRight != NULL)
	{
		pRoot->nMaxRight = ((pRoot->pRight->nMaxLeft > pRoot->pRight->nMaxRight) ? pRoot->pRight->nMaxLeft : pRoot->pRight->nMaxRight) + 1;
	}

	// ���������
	if (pRoot->nMaxLeft + pRoot->nMaxRight > nMaxLen)
	{
		nMaxLen = pRoot->nMaxLeft + pRoot->nMaxRight;
	}
}

