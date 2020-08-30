#include "JZOff.h"

/*    �ݹ飬 Ҫ���м�����
����depth������¼��ǰ�ڵڼ��㣨��0��ʼ���������²�ʱdepth + 1��
���depth >= vector.size()˵����һ�㻹û���������ǵ�һ���������Ե����ݿ���
��Ϊ��ǰ��������� - �� - �ң�����ÿһ����˵����ߵĿ϶����ұ��ȱ���������ʵ���Ϻ���������һ���ġ����� */

class Soltion		//�ݹ飬
{
public:
vector<vector<int>> levelOrder(TreeNode* root) {
	vector<vector<int> > res;

	levelOrder(root, 0, res);

	return res;
}

void levelOrder(TreeNode* root, int depth, vector<vector<int> >& res) //
{
	if (!root)   return;

	if (depth >= res.size())  res.push_back({});

	res[depth].push_back(root->val);

	levelOrder(root->left, depth + 1, res);
	levelOrder(root->right, depth + 1, res);
}
};

class Solution {		//ʹ����������
public:
	vector<vector<int>> levelOrder(TreeNode* root) {

		vector<vector<int>>  res;
		if (root == NULL) return res;
		res.push_back({ root->val });

		queue<TreeNode*> cur;
		queue<TreeNode*> nex;
		vector<int> vec;
		cur.push(root);

		while (root)
		{
			while (!cur.empty()) {
				TreeNode* temp = cur.front();
				if (temp->left)   nex.push(temp->left);
				if (temp->right)  nex.push(temp->right);
				cur.pop();
			}

			while (!nex.empty())
			{
				TreeNode* temp = nex.front();
				cur.push(temp);
				vec.push_back(temp->val);
				nex.pop();

			}


			if (cur.empty() && nex.empty())
				break;

			if (nex.empty())
			{
				res.push_back(vec);
				vec.clear();
			}


		}

		return res;
	}
};