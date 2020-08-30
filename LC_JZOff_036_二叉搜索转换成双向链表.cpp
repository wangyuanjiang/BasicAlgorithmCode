#include "JZOff.h"

//�����������������vector<TreeNode*>�Ȼ�����ε�����������������ָ��

class Solution {
public:
	Node* treeToDoublyList(Node* root) {

		if (!root)   return root;

		stack<Node*> sta;
		vector<Node*> vec;

		while (root || !sta.empty())
		{
			while (root)
			{
				sta.push(root);
				root = root->left;
			}


			root = sta.top();
			sta.pop();
			vec.push_back(root);
			root = root->right;
		}

		vec.front()->left = vec.back();
		vec.back()->right = vec.front();

		for (int i = 0; i < vec.size() - 1; i++)
		{
			vec[i]->right = vec[i + 1];
			vec[i + 1]->left = vec[i];
		}

		return vec.front();
	}
};