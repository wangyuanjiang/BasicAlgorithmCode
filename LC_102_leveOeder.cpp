
#include<iostream>
#include<vector>
#include<queue>
#include<stack>
using namespace std;
 // Definition for a binary tree node.
  struct TreeNode {
      int val;
      TreeNode *left;
     TreeNode *right;
      //TreeNode(int x) : val(x), left(NULL), right(NULL) {}
  };
 
class Solution {  //myself
public:
	vector<vector<int>> levelOrder(TreeNode* root) {
		queue<TreeNode*>q;
		vector<vector<int>>vec;
		vector<int>vec1 = NumOfEveryLevel(root);
		vector<int>vec2, vec3;
		if (!root)
			return vec;
		q.push(root);
		//q.push(root);
		while (!q.empty()) {
			root = q.front();
			q.pop();
			//if (!q.empty() && root == q.front())
				vec2.push_back(root->val);
			//else {
				if (root->left) {
					q.push(root->left);
					//q.push(root->left);
				}
				if (root->right) {
					q.push(root->right);
					//q.push(root->right);
				}
			//}

		}
		int i, j;
		i = 0;
		//auto it=vec2.begin();
		for (auto it = vec2.begin(); it != vec2.end(); ++i) {
			for (j = 0; j < vec1[i];) {
				if (it != vec2.end() && i < vec1.size()) {
					vec3.push_back(*it);
					++it;
					++j;
				}
				else
					break;
			}
			vec.push_back(vec3);
			vec3.clear();
		}
		// vec.clear();
		//  vec.push_back(vec2);
		return vec;
	}

	vector<int> NumOfEveryLevel(TreeNode *root)//求每一层结点的个数
	{
		vector<int>vec;
		if (NULL == root)
		{
			return vec;
		}
		queue<TreeNode*> buf;

		buf.push(root);
		buf.push(NULL);
		int count = 0;
		int level = 0;
		while (buf.size())
		{
			TreeNode *front = buf.front();
			buf.pop();
			if (front == NULL)
			{
				level++;
				//cout << level << " : " << count << endl;
				vec.push_back(count);
				count = 0;
				if (buf.empty())
				{
					break;
				}
				else
				{
					buf.push(NULL);
				}
			}
			else
			{
				count++;
				if (front->left != NULL)
				{
					buf.push(front->left);
				}
				if (front->right != NULL)
				{
					buf.push(front->right);
				}
			}
		}
		return vec;
	}

};

/////////////////////////////////////////////////////////////////////////////////
//递归
/*层序遍历一般来说确实是用队列实现的，但是这里很明显用递归前序遍历就能实现呀，
而且复杂度O(n)。。。

要点有几个：

利用depth变量记录当前在第几层（从0开始），进入下层时depth + 1；
如果depth >= vector.size()说明这一层还没来过，这是第一次来，所以得扩容咯；
因为是前序遍历，中-左-右，对于每一层来说，左边的肯定比右边先被遍历到，实际上后序中序都是一样的。。。*/
class Solution {
public:
	vector<vector<int>> levelOrder(TreeNode* root) {
		vector<vector<int>> ans;
		pre(root, 0, ans);
		return ans;
	}

	void pre(TreeNode *root, int depth, vector<vector<int>> &ans) {
		if (!root) return;
		if (depth >= ans.size())
			ans.push_back(vector<int> {});
		ans[depth].push_back(root->val);
		pre(root->left, depth + 1, ans);
		pre(root->right, depth + 1, ans);
	}
};

////////////////////////////////////////////////////////////////////////////
//可以通过两个队列分别记录当前层的节点以及下一层的节点，遍历当前层节点，将所有儿子节点加入到下一层队列中，
//当当前层队列空时，遍历下一层队列中的节点。直到所有整个树都遍历为止
class Solution {
public:
	vector<vector<int>> levelOrder(TreeNode* root) {
		vector<vector<int>> ans;
		if (root == NULL)
			return ans;
		queue<TreeNode*> Q;//当前层
		Q.push(root);
		queue<TreeNode*> temp;//下一层
		vector<int> t;
		t.push_back(root->val);
		ans.push_back(t);
		while (!Q.empty()) {
			TreeNode* node = Q.front();
			Q.pop();
			if (node->left) {//把当前层队首结点的左右结点压入下一层的队中
				temp.push(node->left);
			}
			if (node->right) {
				temp.push(node->right);
			}
			if (Q.empty() && temp.empty()) {
				break;
			}
			if (Q.empty()) {
				vector<int> t;
				while (!temp.empty()) {
					Q.push(temp.front());//把下一层的队首结点压入当前层
					TreeNode* tTree = temp.front();
					t.push_back(tTree->val);//把结点的val压入vec
					temp.pop();
				}
				ans.push_back(t);
			}
		}
		return ans;
	}
};
class Solution {
public:
	vector<vector<int>> levelOrder(TreeNode* root) {//当前层和下一层交替压入vector<vector<int>>
		queue<TreeNode*>cur;
		vector<vector<int>> ans;
		if (root == NULL)
			return  ans;
		queue<TreeNode*>nex;
		vector<int>tem;
		TreeNode* front;
		cur.push(root);
		tem.push_back(root->val);
		ans.push_back(tem);
		tem.clear();
		while (!cur.empty()) {
			front = cur.front();
			cur.pop();
			if (front->left) {
				nex.push(front->left);
				tem.push_back((front->left)->val);
			}
			if (front->right) {
				nex.push(front->right);
				tem.push_back((front->right)->val);
			}
			if (cur.empty()) {
				if (!tem.empty()) {
					ans.push_back(tem);
					tem.clear();
				}
				while (!nex.empty()) {
					front = nex.front();
					nex.pop();
					if (front->left) {
						cur.push(front->left);
						tem.push_back((front->left)->val);
					}
					if (front->right) {
						cur.push(front->right);
						tem.push_back((front->right)->val);
					}

					if (nex.empty()) {
						if (!tem.empty()) {
							ans.push_back(tem);
							tem.clear();
						}
						break;
					}

				}
			}
		}
		return ans;
	}
};