#include "JZOff.h"

class Solution {
public:
	int kthLargest(TreeNode* root, int k) {		//中序遍历

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
			vec.push_back(root->val); //注意中序遍历是在这里输出，不是在前面输出！！！！！！！！！！！
			root = root->right;
		}

		if (k > vec.size())
			throw "k > the number of node";
		return vec[vec.size() - k];
	}
};

class Solution {	//中序遍历,递归
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

/*这道题不适合用这个方法，因为做题的时候没有注意到输入是二叉查找树，
还以为是普通的二叉树。假如是普通的二叉树的话上面的中序遍历做法就不能用了。
可以维护一个大小为 k 的小顶堆，以任意方式遍历二叉树，将结点值插入该小顶堆，最后输出堆顶元素即可。
*/
class Solution {	//任意遍历+堆
public:
	int kthLargest(TreeNode* root, int k) {
		priority_queue<int, vector<int>, std::greater<int>> pquk;
		for (int i = 0; i < k; i++) {	//先创建大小为k的小顶堆
			pquk.push(0);
		};
		dfs(pquk, root);
		return pquk.top();
	}

	void dfs(priority_queue<int, vector<int>, std::greater<int>> &pquk, TreeNode* node) {
		if (node == nullptr) return;
		if (node->val > pquk.top()) {	//维护大小为k的小顶堆，如果节点点值比队首元素大，则弹出队首元素再将结点值插入队列，
			pquk.pop();
			pquk.push(node->val);
		}
		dfs(pquk, node->left);
		dfs(pquk, node->right);
	}
};

