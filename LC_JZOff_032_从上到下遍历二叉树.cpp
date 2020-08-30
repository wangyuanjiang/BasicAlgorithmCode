#include "JZOff.h"

/*    递归， 要点有几个：
利用depth变量记录当前在第几层（从0开始），进入下层时depth + 1；
如果depth >= vector.size()说明这一层还没来过，这是第一次来，所以得扩容咯；
因为是前序遍历，中 - 左 - 右，对于每一层来说，左边的肯定比右边先被遍历到，实际上后序中序都是一样的。。。 */

class Soltion		//递归，
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

class Solution {		//使用两个队列
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