#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
#include<stdio.h>
using namespace std;

int maxValue(int W, vector<int>& wt, vector<int>& val,int n) {//暴力迭代
	
	if (W == 0 || n==0) return 0;
	if (wt[n - 1] > W)
		return maxValue(W, wt, val, n - 1);
	else
		return max(maxValue(W - wt[n - 1], wt, val, n-1) + val[n], maxValue(W, wt, val, n-1));
} 
/*int maxValueDp(int W, vector<int>& wt, vector<int>& val, int n) {
	if (W == 0 || n == 0) return 0;
	vector<vector<int>>dp(wt.size(), vector<int>(W+1, -1));
	for(int i=0;i<wt.size();i++)
		for (int j = 0; j <= W; j++) {
			if (dp[i][j] != -1) return dp[i][j];
			else if (wt[i] > j)
				dp[i][j]= maxValueDp(j, wt, val, i);
			else
				dp[i][j]= max(maxValueDp(j - wt[i], wt, val, i) + val[i], maxValueDp(W, wt, val, i));
		}
	return dp[wt.size() - 1][W];
}*/

//dp[i][j] 表示有i个物品，背包容量为j时，价值的最大值；
int KnapSack(vector<int>& wt, vector<int>& val, int C) {//比较靠谱
	size_t len = wt.size();
	if (len == 0 || C == 0)
		return 0;
	vector<vector<int>>dp(wt.size(), vector<int>(C + 1, -1));
	for (size_t i = 0; i <= C; i++) {
		dp[0][i] = wt[0] <= i ? val[0] : 0;//初始化第一行
	}
	for (size_t i = 1; i < len; i++) {//填充其他行
		for (size_t j = 0; j <= C; j++) {
			dp[i][j] = dp[i - 1][j];
			if (wt[i] <= j)
				dp[i][j] = max(dp[i][j], dp[i - 1][j - wt[i]] + val[i]);
		}
	}
	return dp[len - 1][C];
}

int max(int a, int b) { return (a > b) ? a : b; }


int knapSack(int W, vector<int>& wt, vector<int>& val) {
	vector<vector<int>>dp(wt.size(), vector<int>(W + 1, -1));
	for (size_t i = 0; i <= W; i++) {
		dp[0][i] = wt[0] <= i ? val[0] : 0;//初始化第一行
	}
	for (int i = 1; i < wt.size(); i++)
		for (int w = 0; w <= W; w++) {
		   if (w < wt[i]) dp[i][w] = dp[i - 1][w];
			else dp[i][w] = max(dp[i - 1][w], val[i] + dp[i - 1][w - wt[i]]);
		}
	return dp[wt.size() - 1][W];
}

int kanpSack1(vector<int>& wt, int C) {
	size_t len = wt.size();
	if (len == 0 || C == 0)
		return 0;
	vector<vector<int>> dp(len, vector<int>(C + 1, -1));
	size_t k = 0, W = 0, zeroNumber = 0;
	while (zeroNumber<len) {
		for (size_t i = 0; i < len; i++) {
			dp[i][0] = 0;
			for (size_t i = 0; i < len; i++)
				for (size_t j = 0; j <= C; j++)
				{
					dp[i][j] = dp[i - 1][j] < dp[i - 1][j - wt[i]] + wt[i] ? dp[i - 1][j - wt[i]] + wt[i] : dp[i - 1][j];
					if (dp[i][j] != dp[i - 1][j])
						wt[i] = 0;
					zeroNumber++;
				}
		}
		//W = W + dp[len-1][C];
		k++;

	}
	return k ;
}