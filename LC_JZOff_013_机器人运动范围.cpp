#include "JZOff.h"

/*地上有一个m行n列的方格，从坐标 [0,0] 到坐标 [m-1,n-1] 。一个机器人从坐标 [0, 0] 的格子开始移动，
它每次可以向左、右、上、下移动一格（不能移动到方格外），也不能进入行坐标和列坐标的数位之和大于k的格子。
例如，当k为18时，机器人能够进入方格 [35, 37] ，因为3+5+3+7=18。但它不能进入方格 [35, 38]，
因为3+5+3+8=19。请问该机器人能够到达多少个格子？
*/
class Solution {
public:
	int movingCount(int m, int n, int k) {
		vector<vector<bool>> used(m, vector<bool>(n, 0));

		int res = backtrack(m, n, k, used, 0, 0);

		return res;

	}
	int backtrack(int m, int n, int k, vector<vector<bool>>& used, int i, int j)
	{
		int res = 0;

		if (i >= 0 && i < m && j < n && j >= 0 && sumofBit(i, j, k) && !used[i][j])
		{
			used[i][j] = true;
			res = 1 + backtrack(m, n, k, used, i - 1, j) 
					+ backtrack(m, n, k, used, i + 1, j)
					+ backtrack(m, n, k, used, i, j - 1) 
					+ backtrack(m, n, k, used, i, j + 1);
		}	//这一题没有状态重置

		return res;
	}

	bool sumofBit(int i, int j, int k)
	{
		int temp = 0;

		while (i > 0)
		{
			temp += i % 10;
			i = i / 10;

		}

		while (j > 0)
		{
			temp += j % 10;
			j = j / 10;

		}

		if (temp <= k)
			return true;

		return false;
	}

};