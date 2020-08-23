
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
////////////////////////////声明///////////////////////////////////////
BSTreeNode *CreateBSTreeNode(DataType x);
bool InsertBSTreeNode(BSTreeNode **pptree, DataType x);
bool InsertBSTreeNode_recursion(BSTreeNode **pptree, DataType x);
bool DeleteBSTreeNode(BSTreeNode **root, DataType x);
BSTreeNode *FindBSTreeNode(BSTreeNode *root, DataType x);
BSTreeNode *FindBSTreeNode_recursion(BSTreeNode *root, DataType x);

//创建结点
BSTreeNode *CreateBSTreeNode(DataType x)
{
	BSTreeNode * node = new BSTreeNode;
	node->_val = x;
	node->_left = NULL;
	node->_right = NULL;
	
	return node;
}
  
// 二叉查找树插入结点

//插入新结点并不会移动现有结点
bool InsertBSTreeNode(BSTreeNode **pptree, DataType x)  
{
	BSTreeNode *parent = NULL;
	BSTreeNode *cur = *pptree;

	if (*pptree == NULL)
	{
		*pptree = CreateBSTreeNode(x);
		return true;
	}

	while (cur)
	{
		parent = cur;	//记录父节点
		if (x > cur->_val)
			cur = cur->_right;
		else if (x < cur->_val)
			cur = cur->_left;
		else
			return false;  //x已经存在
	}

	if(parent->_val < x)  //父节点的值小于插入的的值 插入右子树
		parent->_right = CreateBSTreeNode(x);
	if (parent->_val > x) //  父节点的值大于插入的值， 插入左子树
		parent->_left = CreateBSTreeNode(x);
	return true;
}

// 删除结点，比较复杂要涉及结点的移动；
bool DeleteBSTreeNode(BSTreeNode **root, DataType x)
{
	BSTreeNode *cur = *root;
	BSTreeNode *parent = *root;
	BSTreeNode *del = NULL;

	while (cur)
	{		//寻找结点
		if (cur->_val > x) {
			parent = cur;		// 保存当前结点的父结点
			cur = cur->_left;  //当前结点值大于待删除的值，左移
		}

		else if (cur->_val < x) {
			parent = cur;
			cur = cur->_right;	//当前结点值小于待删除的值，右移
		}
		else	                // 找到了
		{
			del = cur;

			if (cur->_left == NULL) {	//待删除结点的左子树为空

				//保持分支不变性
				if (parent->_left == cur)	//待删除结点是其父结点的左子树，说明待删除结点及其左右子树的值小于其父节点的值
					parent->_left = cur->_right;	//令待删除结点的父节点的左子树指向待删除结点的右子树
				else if (parent->_right == cur)		//待删除结点是其父结点的左子树，说明待删除结点及其左右子树的值大于于其父节点的值
					parent->_right = cur->_right;	//令待删除结点的父节点的右子树指向待删除结点的右子树
				
				else if (parent == cur)		//没有父结点时，即带删除结点是根结点
					*root = parent->_right;
			}
			else if (cur->_right == NULL) {		//待删除结点的右子树为空
				if (parent->_right == cur)
					parent->_right = cur->_left;

				else if (parent->_left == cur)
					parent->_left = cur->_left;

				else if (parent == cur)		//没有父结点时，即带删除结点是根结点
					*root = parent->_left;
			}
			else {							//左右子树都不为空，在它的右子树中寻找中序下的第一个结点(结点值最小)，用它的值填补到被删除节点中，再在来处理该结点的删除问题


				BSTreeNode *sub = cur->_right; //右子树

				while (sub->_left)  //右子树里寻找最小的   也可以左字数里寻找最大的
				{
					parent = sub;
					sub = sub->_left;
				}
				del = sub;

				cur->_val = sub->_val;		//在它的右子树中寻找中序下的第一个结点(结点值最小)，用它的值填补到被删除节点中，再在来处理该结点的删除问题


				if (parent->_left == sub)
					parent->_left = sub->_right;
				if (parent->_right == sub)
					parent->_right == sub->_right;
			}
			delete del;
			del = NULL;
			return true;
		}
	}
	return false;
}

// 递归法插入结点 
bool InsertBSTreeNode_recursion(BSTreeNode **pptree, DataType x)
{
	//cout << (**pptree)._val;  解引用指向指针的指针

	if (*pptree == NULL)
	{
		*pptree = CreateBSTreeNode(x);
		return true;
	}

	if (x > (*pptree)->_val)    //等价于(**pptree)._val
		InsertBSTreeNode_recursion(&(*pptree)->_right, x);		//&的意思是传进来节点指针的引用,目的是让传递进来的指针发生改变
	
	else if (x < (*pptree)->_val)
		InsertBSTreeNode_recursion(&(*pptree)->_left, x);

	else
			return false;
}

//非递归方法查找；
	BSTreeNode *FindBSTreeNode(BSTreeNode *root, DataType x)
	{
		BSTreeNode *cur = root;
		while (cur )
		{
			if (cur->_val == x)
				return cur;
			else if (cur->_val < x)
				cur = cur->_right;
			else
				cur = cur->_left;
		}
		return NULL;
	}


	//递归方法查找
	BSTreeNode *FindBSTreeNode_recursion(BSTreeNode *root, DataType x)
	{
		if (!root)
			return NULL;
		if (root->_val > x)
			FindBSTreeNode_recursion(root->_left, x);
		else if (root->_val < x)
			FindBSTreeNode_recursion(root->_right, x);
		else
			return root;
	}