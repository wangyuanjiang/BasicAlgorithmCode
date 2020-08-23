#include <iostream>
#include <stack>
#include <vector>

using namespace std;

typedef int DataType;

typedef struct BSTreeNode
{
	struct BSTreeNode *_left;
	struct BSTreeNode *_right;
	DataType _val;
}BSTreeNode;
BSTreeNode *CreateBSTreeNode(DataType x);
BSTreeNode *FindBSTreeNode(BSTreeNode *root, DataType x);
BSTreeNode *FindBSTreeNode_recursion(BSTreeNode *root, DataType x);
bool InsertBSTreeNode(BSTreeNode **pptree, DataType x);


BSTreeNode *CreateBSTreeNode(DataType x) {

	BSTreeNode *tem = new BSTreeNode;

	tem->_val = x;
	tem->_left = NULL;
	tem->_right = NULL;

	return tem;

}
BSTreeNode *FindBSTreeNode(BSTreeNode *root, DataType x) {
	
	BSTreeNode *cur = root;
	while (cur) {
	
		if (cur->_val < x)
			cur = cur->_right;
		else if (cur->_val > x)
			cur = cur->_left;
		else
		{
			return cur;
		}
	}

	return NULL;
}

BSTreeNode *FindBSTreeNode_recursion(BSTreeNode *root, DataType x)
{
	if (!root)
		return NULL;
	
	if (x == root->_val)
		return root;
	else if (root->_val > x)
		FindBSTreeNode_recursion(root->_left, x);
	else
		FindBSTreeNode_recursion(root->_right, x);
	
}

bool InsertBSTreeNode(BSTreeNode **pptree, DataType x)
{
	if (*pptree == NULL) {		//	如果pptree 为空直接插入；
		*pptree = CreateBSTreeNode(x); 
		return true;
	}

	//if (FindBSTreeNode(*pptree, x) == NULL)
		//return false;

	BSTreeNode * cur = *pptree;
	BSTreeNode *parent = *pptree;
	while (cur) {
	
		parent = cur;

		if (cur->_val > x)
			cur = cur->_left;
		else if (cur->_val < x)
			cur = cur->_right;
		else
			return false;  // 如果已经存在直接返回false
	}

	if(x > parent->_val) //如果x大于结点值插入右子树
		parent->_right = CreateBSTreeNode(x);
	if(x < parent->_val) // 如果小于结点值插入左子树
		parent->_left = CreateBSTreeNode(x);
	return true;

}

bool DeleteBSTreeNode(BSTreeNode **root, DataType x)
{
	BSTreeNode *cur = *root;
	BSTreeNode *pre;
	if (!*root)
		return false;

	while (cur)
	{
		pre = cur;
		if (x > cur->_val)
			cur = cur->_right;
		else if (x < cur->_val)
			cur = cur->_left;
		
	}

	if (!cur->_left && !cur->_right) {
		if (cur == pre->_left)
			pre->_left = NULL;
		if (cur == pre->_right)
			pre->_right = NULL;
	}

	else if (cur->_left && !cur->_right) {
		if (cur == pre->_left)
			pre->_left = cur->_left;
		if (cur == pre->_right)
				pre->_right = cur->_left;
	}
	else if (!cur->_left && cur->_right) {
		if (cur == pre->_left)
			pre->_left = cur->_right;
		if (cur == pre->_right)
			pre->_right = cur->_right;
	}

	else
	{
		BSTreeNode *tem = cur->_left;
		BSTreeNode *pre1;
		while (tem)
		{
			pre1 = tem;
			tem = tem->_right;
		}

		cur->_val = tem->_val;
		pre1->_right = NULL;
	}

	return true;
}

