#include<iostream>
#include<vector>
#include<algorithm>
#include <set>
using namespace std;

class Solution {		//others 剪枝法
public:
	vector<vector<int>> permuteUnique(vector<int>& nums) {

		sort(nums.begin(), nums.end());		// nums不排序不行， 只有排序后相邻的才可能相等，才可以判断去除！！！！！
		vector<vector<int>> res;
		int len = nums.size();
		vector<bool> flag(len, true);
		vector<int> tem;

		dfs(nums, flag, res, tem, 0);


		return res;
	}

	void dfs(vector<int>& nums, vector<bool>& flag, vector<vector<int>>& set1, vector<int>& tem, int ix) {

		size_t len = nums.size();

		//vector<int> tem(len, 0);
		if (ix == len) {
			set1.push_back(tem);
			return;
		}
		//set1.push_back(tem);
		for (int i = 0; i < len; i++)
		{
			if (flag[i]) {
				//i-1和i的值相等，且i-1没被用过（之后可能会被用就产生重复）flag【i-1】=true 是取相等的数中最左边的那个数当ll的第一个数，而flag【i-1】=false就是取相等的数中最右边的那个数当ll的第一个数，也就是说分别取第一行和第二行。
				if (i > 0 && nums[i] == nums[i - 1] && flag[i - 1])// 剪枝，虽然flag[i-1] = false和true都行，但是不能拿掉flag[i-1]
					continue;

				tem.push_back(nums[i]);
				flag[i] = false;
				dfs(nums, flag, set1, tem, ix + 1);
				flag[i] = true;
				tem.pop_back();
			}
		}
	}
};

class Solution {	//解法一： 回溯法+set 利用set保证唯一性；myself
public:
	vector<vector<int>> permuteUnique(vector<int>& nums) { // nums不排序也行

		vector<vector<int>> res;
		int len = nums.size();
		vector<bool> flag(len, true);
		vector<int> tem(len, 0);
		set<vector<int>> set1;
		dfs(nums, flag, set1, tem, 0);
		for (auto it = set1.begin(); it != set1.end(); it++)
			res.push_back(*it);

		return res;
	}

	void dfs(vector<int>& nums, vector<bool>& flag, set<vector<int>>& set1, vector<int>& tem, int ix) {

		size_t len = nums.size();

		//vector<int> tem(len, 0);
		if (ix == len) {
			set1.insert(tem);
			return;
		}
		//set1.push_back(tem);
		for (int i = 0; i < len; i++)
		{
			if (flag[i]) {
				tem[i] = nums[ix];
				flag[i] = false;
				dfs(nums, flag, set1, tem, ix + 1);
				flag[i] = true;
			}
		}
	}
};

class Solution {	//剪支，但是这样不行，要 tem.push_back()和tem.pop_back();
public:
	vector<vector<int>> permuteUnique(vector<int>& nums) {
		sort(nums.begin(), nums.end());
		vector<vector<int>> res;
		int len = nums.size();
		vector<bool> flag(len, true);
		vector<int> tem(len, 0);
		//set<vector<int>> set1;
		dfs(nums, flag, res, tem, 0);
		//for (auto it = set1.begin(); it != set1.end(); it++)
			//res.push_back(*it);

		return res;
	}

	void dfs(vector<int>& nums, vector<bool>& flag, vector<vector<int>>& set1, vector<int>& tem, int ix) {

		size_t len = nums.size();

		//vector<int> tem(len, 0);
		if (ix == len) {
			set1.push_back(tem);
			return;
		}
		//set1.push_back(tem);
		for (int i = 0; i < len; i++)
		{
			if (flag[i]) {
				if (i > 0 && nums[i] == nums[i - 1] && flag[i - 1])
					continue;

				tem[i] = nums[ix];
				flag[i] = false;
				dfs(nums, flag, set1, tem, ix + 1);
				flag[i] = true;
			}
		}
	}
};




class MyDec181902 {  //同于解法一，回溯法+set，利用set保证唯一性；

public:
	void backtrack(
		vector<int>& nums,
		vector<int> path,
		set<vector<int>>& set1,
		vector<bool>& visited,
		int currenszie);
	vector<vector<int>> permute(vector<int>& nums) {
		set<vector<int>> set1;
		vector<vector<int>> ans;
		vector<int> path;
		vector<bool> visited(nums.size(), false);
		int currensize = 0;
		backtrack(nums, path, set1, visited, currensize);
		for (auto it = set1.begin(); it != set1.end(); ++it)
			ans.push_back(*it);
		return ans;
	}


};

void  MyDec181902::backtrack(		//一般回溯的模板
	vector<int>& nums,
	vector<int> path,
	set<vector<int>>& set1,
	vector<bool>& visited,
	int currenszie)

{
	if (currenszie == nums.size()) {
		set1.insert(path);
		return;
	}

	for (int i = 0; i < nums.size(); i++) {

		if (!visited[i]) {	//visited[i]==false 表示没有被加入path中；

			path.push_back(nums[i]);
			visited[i] = true;
			backtrack(nums, path, set1, visited, currenszie + 1);
			// 回溯的时候，一定要记得状态重置！！！！！！！！！！！！！
			path.pop_back();
			visited[i] = false;

		}
	}

}
/*
可以通过这个例子理解“回溯”算法的“状态重置”的操作，“回溯搜索” = “深度优先遍历 + 状态重置 + 剪枝”。（“剪枝”可以通过第 47 题来理解。）

1、“深度优先遍历” 就是“不撞南墙不回头”(DFS)；

2、回头的时候要“状态重置”，即回到上一次来到的那个地方，“状态”要和上一次来的时候一样。!!!!!!!!!!!!!

3、在代码上，往往是在执行下一层递归的前后，代码的形式是“对称的”。!!!!!!!!!!!!!!!!!!!!
*/


