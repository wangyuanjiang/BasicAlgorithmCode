
#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
using namespace std;

/*有 N 堆金币排成一排，第 i 堆中有 C[i] 块金币。每次合并都会将相邻的两堆金币合并为一堆，
成本为这两堆金币块数之和。经过N-1次合并，最终将所有金币合并为一堆。请找出将金币合并为一堆的最低成本。
其中，1 <= N <= 30，1 <= C[i] <= 100*/


int main_MergeGoldCoin()
{
	int n = 0;
	while (cin >> n)
	{
		vector<int> v(n + 1);
		vector<vector<int>> dp(n + 1, vector<int>(n + 1, INT_MAX));
		vector<vector<int>> sum(n + 1, vector<int>(n + 1, 0));
		for (int i = 1; i <= n; i++)
		{
			cin >> v[i];
		}
		for (int i = 1; i <= n; i++)
		{
			sum[i][i] = v[i];
			dp[i][i] = 0;
		}
		for (int len = 1; len < n; len++)  // 区间长度
		{
			for (int i = 1; i + len <= n; i++)  //区间起点
			{
				int j = i + len; //区间终点
				for (int k = i; k < j; k++)
				{
					sum[i][j] = sum[i][k] + sum[k + 1][j];
					dp[i][j] = min(dp[i][j], dp[i][k] + dp[k + 1][j] + sum[i][j]);
				}
			}
		}
		cout << dp[1][n] << endl;

	}
}