#include<iostream>
#include<vector>
#include<algorithm>
#include <set>
using namespace std;

class Solution {		//others ��֦��
public:
	vector<vector<int>> permuteUnique(vector<int>& nums) {

		sort(nums.begin(), nums.end());		// nums�������У� ֻ����������ڵĲſ�����ȣ��ſ����ж�ȥ������������
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
				//i-1��i��ֵ��ȣ���i-1û���ù���֮����ܻᱻ�þͲ����ظ���flag��i-1��=true ��ȡ��ȵ���������ߵ��Ǹ�����ll�ĵ�һ��������flag��i-1��=false����ȡ��ȵ��������ұߵ��Ǹ�����ll�ĵ�һ������Ҳ����˵�ֱ�ȡ��һ�к͵ڶ��С�
				if (i > 0 && nums[i] == nums[i - 1] && flag[i - 1])// ��֦����Ȼflag[i-1] = false��true���У����ǲ����õ�flag[i-1]
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

class Solution {	//�ⷨһ�� ���ݷ�+set ����set��֤Ψһ�ԣ�myself
public:
	vector<vector<int>> permuteUnique(vector<int>& nums) { // nums������Ҳ��

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

class Solution {	//��֧�������������У�Ҫ tem.push_back()��tem.pop_back();
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




class MyDec181902 {  //ͬ�ڽⷨһ�����ݷ�+set������set��֤Ψһ�ԣ�

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

void  MyDec181902::backtrack(		//һ����ݵ�ģ��
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

		if (!visited[i]) {	//visited[i]==false ��ʾû�б�����path�У�

			path.push_back(nums[i]);
			visited[i] = true;
			backtrack(nums, path, set1, visited, currenszie + 1);
			// ���ݵ�ʱ��һ��Ҫ�ǵ�״̬���ã�������������������������
			path.pop_back();
			visited[i] = false;

		}
	}

}
/*
����ͨ�����������⡰���ݡ��㷨�ġ�״̬���á��Ĳ����������������� = ��������ȱ��� + ״̬���� + ��֦����������֦������ͨ���� 47 ������⡣��

1����������ȱ����� ���ǡ���ײ��ǽ����ͷ��(DFS)��

2����ͷ��ʱ��Ҫ��״̬���á������ص���һ���������Ǹ��ط�����״̬��Ҫ����һ������ʱ��һ����!!!!!!!!!!!!!

3���ڴ����ϣ���������ִ����һ��ݹ��ǰ�󣬴������ʽ�ǡ��ԳƵġ���!!!!!!!!!!!!!!!!!!!!
*/


