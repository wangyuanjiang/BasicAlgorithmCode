
#include "JZOff.h"

class Solution {  //���˷��ݹ����
public:
	TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
		//�ݹ����
		return recursionBuild(preorder.begin(), preorder.end(), inorder.begin(), inorder.end());
	}

	//�ݹ����
	TreeNode* recursionBuild(vector<int>::iterator preBegin, vector<int>::iterator preEnd, vector<int>::iterator inBegin, vector<int>::iterator inEnd)
	{
		if (inEnd == inBegin) return NULL;	//�������ᱨ��
		//��������ǰ������еĵ�һλһ���Ǹ��ڵ�
		TreeNode* cur = new TreeNode(*preBegin);
		//�ҵ����ڵ�����������е�λ�ã��������֮ǰ�Ľڵ㶼���������ڵ㣬֮�����������ڵ�
		auto root = find(inBegin, inEnd, *preBegin); //����ҵ����ص�����
		cur->left = recursionBuild(preBegin + 1, preBegin + (root - inBegin) + 1, inBegin, root);
		cur->right = recursionBuild(preBegin + 1 + (root - inBegin), preEnd, root + 1, inEnd);
		return cur;
	}//����ϵ����Ҫ�в�����root ��������root�� root+1��������root�� root
	//ǰ��ϵ���ڿ�ͷ����root��������preBegin + 1
};


class Solution {  //�������õ�
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
