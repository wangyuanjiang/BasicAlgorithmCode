#include "JZOff.h"

/*在一个 m*n 的棋盘的每一格都放有一个礼物，每个礼物都有一定的价值（价值大于 0）。
你可以从棋盘的左上角开始拿格子里的礼物，并每次向右或者向下移动一格、直到到达棋盘的右下角。
给定一个棋盘及其上面的礼物的价值，请计算你最多能拿到多少价值的礼物？*/


/*1、动态规划的状态dp[i][j]表示到位置（i, j）可获得的最大礼物价值；
2、动态规划的递推公式为dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]) + grid[i][j];
3、动态规划的边界条件为：第一行（第一列）只能从左至右（从上至下）累加；*/

class  Solution
{				//动态规划
public:

	int maxValue(vector<vector<int>>& grid) {
	
		int rows = grid.size();
		int cols = grid[0].size();

		vector<vector<int>> dp(rows, vector<int>(cols, 0));
		dp[0][0] = grid[0][0];
		for (int i = 1; i < rows; i++)
			dp[i][0] = dp[i-1][0] + grid[i][0];
		for (int j = 1; j < cols; j++)
			dp[0][j] = dp[0][j - 1] + grid[0][j];


		for (int i = 1; i < rows; i++) {
			for (int j = 1; j < cols; j++)
			{
				dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]) + grid[i][j];
			}
		}

		return dp[rows - 1][cols - 1];
	}


};

