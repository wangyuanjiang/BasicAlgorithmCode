#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;
class solusion {
	vector<vector<int>> permute(vector<int>& nums) {//ȫ���У��ݹ飻��ⲻ�ˣ�
		vector<vector<int>> ans;
		backtrack(nums, ans, 0);
		return ans;
	}

	void swap(int& a, int& b) {
		int temp = a;
		a = b;
		b = temp;
	}

	void backtrack(vector<int>& nums, vector<vector<int>>& ans, int frist) {//�ݹ�
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
/*�ݹ�˼·
���ȣ����ڵ� 1 λ�����ܵ������ n �֣�ʣ�µ� n - 1 λ�������п��Եݹ���⣻
����Ҫ����� 1 �������ǣ�ʣ�µ� n - 1 λ�������в��ܹ��������ڵ� 1 λ���Ǹ��������ݡ�ѡ�����򡱵�˼�룬��ʣ�µ� n - 1 λ�����ν������� 1 λ���ɡ�
*/
class Solution {
public:
	vector<vector<int>> permute(vector<int>& nums) {//����STL ��ȫ���к�����
		sort(nums.begin(), nums.end());
		vector<vector<int>> result;
		do {
			result.push_back(nums);
		} while (next_permutation(nums.begin(), nums.end()));//ȫ���к�����

		return result;
	}
};

//#include<stack>
//reference https://leetcode-cn.com/problems/permutations/solution/hui-su-suan-fa-python-dai-ma-java-dai-ma-by-liweiw/
class MyDec181901 {  //�������Ļ��ݷ���

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

void  MyDec181901 :: backtrack(		//һ����ݵ�ģ��
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

		if (!visited[i]) {	//visited[i]==false ��ʾû�б�����path�У�

			path.push_back(nums[i]);
			visited[i] = true;
			backtrack(nums, path, ans, visited, currenszie + 1);
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


