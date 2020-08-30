#include "JZOff.h"

class Solution {
public:
	int kthLargest(TreeNode* root, int k) {		//�������

		stack<TreeNode*> sta;
		vector<int> vec;
		int res = 0;
		while (root || !sta.empty()) {

			while (root)
			{
				sta.push(root);
				root = root->left;
			}


			root = sta.top();
			sta.pop();
			vec.push_back(root->val); //ע����������������������������ǰ���������������������������
			root = root->right;
		}

		if (k > vec.size())
			throw "k > the number of node";
		return vec[vec.size() - k];
	}
};

class Solution {	//�������,�ݹ�
public:
	int kthLargest(TreeNode* root, int k) {
		if (root == nullptr || k == 0)
			throw "invalid input";

		 TreeNode * temp = kthLargestCore(root, k);

		 return temp->val;

	}

	TreeNode* kthLargestCore(TreeNode* root, int k)
	{
		TreeNode* temp = nullptr;

		if (root->left);
		temp = kthLargestCore(root->left, k);

		if (temp == nullptr)
		{
			if (k == 1) 	temp = root;

			k--;
		}

		if(temp == nullptr && root->right)
			temp = kthLargestCore(root->right, k);

	}
};

/*����ⲻ�ʺ��������������Ϊ�����ʱ��û��ע�⵽�����Ƕ����������
����Ϊ����ͨ�Ķ���������������ͨ�Ķ������Ļ������������������Ͳ������ˡ�
����ά��һ����СΪ k ��С���ѣ������ⷽʽ�����������������ֵ�����С���ѣ��������Ѷ�Ԫ�ؼ��ɡ�
*/
class Solution {	//�������+��
public:
	int kthLargest(TreeNode* root, int k) {
		priority_queue<int, vector<int>, std::greater<int>> pquk;
		for (int i = 0; i < k; i++) {	//�ȴ�����СΪk��С����
			pquk.push(0);
		};
		dfs(pquk, root);
		return pquk.top();
	}

	void dfs(priority_queue<int, vector<int>, std::greater<int>> &pquk, TreeNode* node) {
		if (node == nullptr) return;
		if (node->val > pquk.top()) {	//ά����СΪk��С���ѣ�����ڵ��ֵ�ȶ���Ԫ�ش��򵯳�����Ԫ���ٽ����ֵ������У�
			pquk.pop();
			pquk.push(node->val);
		}
		dfs(pquk, node->left);
		dfs(pquk, node->right);
	}
};

