
#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
using namespace std;

class Solution {
public:
	int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {

		int w = obstacleGrid.size(); //行数
		int h = obstacleGrid[0].size(); // 列数
		if (w == 0)
			return 0;

		vector<vector<long long>> dp(w, vector<long long>(h, 0));  //如果是int 型的会超出范围

		if (obstacleGrid[0][0] == 0)
			dp[0][0] = 1;
		else
			return 0;

		for (int i = 1; i < h; i++)
			dp[0][i] = obstacleGrid[0][i] == 1 ? 0 : dp[0][i - 1];
		for (int i = 1; i < w; i++)
			dp[i][0] = obstacleGrid[i][0] == 1 ? 0 : dp[i - 1][0];

		for (int i = 1; i < w; i++)
			for (int j = 1; j < h; j++)
				dp[i][j] = obstacleGrid[i][j] == 1 ? 0 : dp[i - 1][j] + dp[i][j - 1];

		return dp[w - 1][h - 1];
	}


};