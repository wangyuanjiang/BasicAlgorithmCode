#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
#include<stack>
using namespace std;
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
	
};

//中序遍历的时候顺便判断是否是递增
bool isValidBST(TreeNode* root) {
	vector<int> ans;
	if (!root) return true;
	stack<TreeNode*> s;
	int ix = 0;
	while (root || !s.empty()) {
		while (root) {  //切记 不是 if！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！
			s.push(root);
			root = root->left;
		}
		root = s.top();
		ans.push_back(root->val);
		if (ix > 0 && ans[ix - 1] >= ans[ix])
			return false;

		ix++;
		s.pop();
		root = root->right;
	}
	return true;
}

//先中序遍历再判断是否是递增的
vector<int>midOreder(TreeNode* root) {
	vector<int> ans;
	if (!root) return ans;
	stack<TreeNode*> s;
	while (root || !s.empty()) {
		while (root) {  //切记 不是 if！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！
			s.push(root);
			root = root->left;
		}
		root = s.top();
		ans.push_back(root->val);
		s.pop();
		root = root->right;
	}
	return ans;
}
bool isValidBST(TreeNode* root) {
	if (root == NULL) return true;
	vector<int>vec(midOreder(root));
	vector<int>tem(midOreder(root));
	sort(vec.begin(), vec.end());
	/*bool ix=0;
for(size_t it=0;it<vec.size()-1;++it)
 {
   //int64_t  ix= *it-*(it+1);
		if (vec[it]==vec[it+1]) {
		   ix=1;
			break;
		}
 }*/
 //for(auto it=vec.begin();it<vec.end()-1;it++)
 //if(*it==*(it+1)) return false;
	for (auto it = vec.begin(); it < vec.end() - 1;)
		if (*it == *++it) return false;

	if (vec != tem)
		return false;
	else
		return true;
}