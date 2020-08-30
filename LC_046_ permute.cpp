#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;
class solusion {
	vector<vector<int>> permute(vector<int>& nums) {//全排列，递归；理解不了；
		vector<vector<int>> ans;
		backtrack(nums, ans, 0);
		return ans;
	}

	void swap(int& a, int& b) {
		int temp = a;
		a = b;
		b = temp;
	}

	void backtrack(vector<int>& nums, vector<vector<int>>& ans, int frist) {//递归
		if (frist== nums.size())
			ans.push_back(nums);
		for (int j = frist; j < nums.size(); j++)
		{
			swap(nums[frist], nums[j]);
			backtrack(nums, ans, frist + 1);
			swap(nums[frist], nums[j]);
		}

	}
};
/*递归思路
首先，排在第 1 位，可能的情况有 n 种，剩下的 n - 1 位数的排列可以递归求解；
不过要解决的 1 个问题是，剩下的 n - 1 位数的排列不能够包括排在第 1 位的那个数，根据“选择排序”的思想，把剩下的 n - 1 位数依次交换到第 1 位即可。
*/
class Solution {
public:
	vector<vector<int>> permute(vector<int>& nums) {//利用STL 的全排列函数；
		sort(nums.begin(), nums.end());
		vector<vector<int>> result;
		do {
			result.push_back(nums);
		} while (next_permutation(nums.begin(), nums.end()));//全排列函数；

		return result;
	}
};

//#include<stack>
//reference https://leetcode-cn.com/problems/permutations/solution/hui-su-suan-fa-python-dai-ma-java-dai-ma-by-liweiw/
class MyDec181901 {  //容易理解的回溯法；

public:
	void backtrack(
		vector<int>& nums,
		vector<int> path,
		vector<vector<int>>& ans,
		vector<bool>& visited,
		int currenszie);
	vector<vector<int>> permute(vector<int>& nums) {
	
		vector<vector<int>> ans;
		vector<int> path;
		vector<bool> visited(nums.size(), false);
		int currensize = 0;
		backtrack(nums, path, ans, visited, currensize);
		return ans;
	}

	
};

void  MyDec181901 :: backtrack(		//一般回溯的模板
	vector<int>& nums,
	vector<int> path,
	vector<vector<int>>& ans,
	vector<bool>& visited,
	int currenszie)

{
	if (currenszie == nums.size()) {
		ans.push_back(path);
		return;
	}

	for (int i = 0; i < nums.size(); i++) {

		if (!visited[i]) {	//visited[i]==false 表示没有被加入path中；

			path.push_back(nums[i]);
			visited[i] = true;
			backtrack(nums, path, ans, visited, currenszie + 1);
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


