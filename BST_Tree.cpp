
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
////////////////////////////����///////////////////////////////////////
BSTreeNode *CreateBSTreeNode(DataType x);
bool InsertBSTreeNode(BSTreeNode **pptree, DataType x);
bool InsertBSTreeNode_recursion(BSTreeNode **pptree, DataType x);
bool DeleteBSTreeNode(BSTreeNode **root, DataType x);
BSTreeNode *FindBSTreeNode(BSTreeNode *root, DataType x);
BSTreeNode *FindBSTreeNode_recursion(BSTreeNode *root, DataType x);

//�������
BSTreeNode *CreateBSTreeNode(DataType x)
{
	BSTreeNode * node = new BSTreeNode;
	node->_val = x;
	node->_left = NULL;
	node->_right = NULL;
	
	return node;
}
  
// ���������������

//�����½�㲢�����ƶ����н��
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
		parent = cur;	//��¼���ڵ�
		if (x > cur->_val)
			cur = cur->_right;
		else if (x < cur->_val)
			cur = cur->_left;
		else
			return false;  //x�Ѿ�����
	}

	if(parent->_val < x)  //���ڵ��ֵС�ڲ���ĵ�ֵ ����������
		parent->_right = CreateBSTreeNode(x);
	if (parent->_val > x) //  ���ڵ��ֵ���ڲ����ֵ�� ����������
		parent->_left = CreateBSTreeNode(x);
	return true;
}

// ɾ����㣬�Ƚϸ���Ҫ�漰�����ƶ���
bool DeleteBSTreeNode(BSTreeNode **root, DataType x)
{
	BSTreeNode *cur = *root;
	BSTreeNode *parent = *root;
	BSTreeNode *del = NULL;

	while (cur)
	{		//Ѱ�ҽ��
		if (cur->_val > x) {
			parent = cur;		// ���浱ǰ���ĸ����
			cur = cur->_left;  //��ǰ���ֵ���ڴ�ɾ����ֵ������
		}

		else if (cur->_val < x) {
			parent = cur;
			cur = cur->_right;	//��ǰ���ֵС�ڴ�ɾ����ֵ������
		}
		else	                // �ҵ���
		{
			del = cur;

			if (cur->_left == NULL) {	//��ɾ������������Ϊ��

				//���ַ�֧������
				if (parent->_left == cur)	//��ɾ��������丸������������˵����ɾ����㼰������������ֵС���丸�ڵ��ֵ
					parent->_left = cur->_right;	//���ɾ�����ĸ��ڵ��������ָ���ɾ������������
				else if (parent->_right == cur)		//��ɾ��������丸������������˵����ɾ����㼰������������ֵ�������丸�ڵ��ֵ
					parent->_right = cur->_right;	//���ɾ�����ĸ��ڵ��������ָ���ɾ������������
				
				else if (parent == cur)		//û�и����ʱ������ɾ������Ǹ����
					*root = parent->_right;
			}
			else if (cur->_right == NULL) {		//��ɾ������������Ϊ��
				if (parent->_right == cur)
					parent->_right = cur->_left;

				else if (parent->_left == cur)
					parent->_left = cur->_left;

				else if (parent == cur)		//û�и����ʱ������ɾ������Ǹ����
					*root = parent->_left;
			}
			else {							//������������Ϊ�գ���������������Ѱ�������µĵ�һ�����(���ֵ��С)��������ֵ�����ɾ���ڵ��У�����������ý���ɾ������


				BSTreeNode *sub = cur->_right; //������

				while (sub->_left)  //��������Ѱ����С��   Ҳ������������Ѱ������
				{
					parent = sub;
					sub = sub->_left;
				}
				del = sub;

				cur->_val = sub->_val;		//��������������Ѱ�������µĵ�һ�����(���ֵ��С)��������ֵ�����ɾ���ڵ��У�����������ý���ɾ������


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

// �ݹ鷨������ 
bool InsertBSTreeNode_recursion(BSTreeNode **pptree, DataType x)
{
	//cout << (**pptree)._val;  ������ָ��ָ���ָ��

	if (*pptree == NULL)
	{
		*pptree = CreateBSTreeNode(x);
		return true;
	}

	if (x > (*pptree)->_val)    //�ȼ���(**pptree)._val
		InsertBSTreeNode_recursion(&(*pptree)->_right, x);		//&����˼�Ǵ������ڵ�ָ�������,Ŀ�����ô��ݽ�����ָ�뷢���ı�
	
	else if (x < (*pptree)->_val)
		InsertBSTreeNode_recursion(&(*pptree)->_left, x);

	else
			return false;
}

//�ǵݹ鷽�����ң�
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


	//�ݹ鷽������
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