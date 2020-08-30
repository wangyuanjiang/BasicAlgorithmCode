
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

	vector<int> NumOfEveryLevel(TreeNode *root)//��ÿһ����ĸ���
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
//�ݹ�
/*�������һ����˵ȷʵ���ö���ʵ�ֵģ���������������õݹ�ǰ���������ʵ��ѽ��
���Ҹ��Ӷ�O(n)������

Ҫ���м�����

����depth������¼��ǰ�ڵڼ��㣨��0��ʼ���������²�ʱdepth + 1��
���depth >= vector.size()˵����һ�㻹û���������ǵ�һ���������Ե����ݿ���
��Ϊ��ǰ���������-��-�ң�����ÿһ����˵����ߵĿ϶����ұ��ȱ���������ʵ���Ϻ���������һ���ġ�����*/
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
//����ͨ���������зֱ��¼��ǰ��Ľڵ��Լ���һ��Ľڵ㣬������ǰ��ڵ㣬�����ж��ӽڵ���뵽��һ������У�
//����ǰ����п�ʱ��������һ������еĽڵ㡣ֱ������������������Ϊֹ
class Solution {
public:
	vector<vector<int>> levelOrder(TreeNode* root) {
		vector<vector<int>> ans;
		if (root == NULL)
			return ans;
		queue<TreeNode*> Q;//��ǰ��
		Q.push(root);
		queue<TreeNode*> temp;//��һ��
		vector<int> t;
		t.push_back(root->val);
		ans.push_back(t);
		while (!Q.empty()) {
			TreeNode* node = Q.front();
			Q.pop();
			if (node->left) {//�ѵ�ǰ����׽������ҽ��ѹ����һ��Ķ���
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
					Q.push(temp.front());//����һ��Ķ��׽��ѹ�뵱ǰ��
					TreeNode* tTree = temp.front();
					t.push_back(tTree->val);//�ѽ���valѹ��vec
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
	vector<vector<int>> levelOrder(TreeNode* root) {//��ǰ�����һ�㽻��ѹ��vector<vector<int>>
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