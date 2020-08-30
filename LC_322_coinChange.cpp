#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int helper(vector<int>& , vector<int>& , int );

int coinChange(vector<int>&coins, int target) {
	vector<int> dp(target + 1, -2);
	return helper(coins, dp, target);

}
int  helper(vector<int>&coins, vector<int>&dp, int n) {//带备忘录的递归
	if (n == 0) return 0;
	if (dp[n] != -2) return dp[n];
	int ans = n + 1;
	for (int ci : coins) {
		if (n < ci) continue;
		int subProb = helper(coins, dp, n - ci);
		if (subProb == -1) continue;
		ans = min(ans, subProb);
	}
	dp[n] = ans == n + 1 ? -1 : ans;
	return dp[n];
}

int coinChange1(vector<int>& coins, int target) {//暴力递归
	if (coins.size() == 0 || target == 0)
		return 0;
	int ans = target + 1;
	for (int ci : coins) {
		if (target < ci) continue;
		int subProb = coinChange1(coins, target-ci);
		if (subProb == -1) continue;
		ans = min(ans, subProb + 1);
	}
	return ans == target + 1 ? -1 : ans;
}

int coinChangeDp(vector<int>& coins, int target) {//自底向上动态规划
	vector<int>dp(target+1, target+ 1);		//如果能够兑换，所需要的零钱数最多为target,即全部换成面值为1的零钱；
	dp[0] = 0; 
	for (int i = 0; i <= target; i++) {
		for (int ci : coins) {
			if (ci < i)
				dp[i] = min(dp[i], dp[i - ci] + 1);
		}
	}
	return dp[target] == target + 1 ? -1 : dp[target];
}

class Solution {	//myself1
public:
	int coinChange(vector<int>& coins, int amount) {
		vector<int> dp(amount + 1, -1);
		dp[0] = 0;
		for (int i = 1; i <= amount; i++) {
			int min = amount + 1;
			for (auto ci : coins) {
				if (i < ci)
					continue;
				if (min > dp[i - ci] && dp[i - ci] >= 0)
					min = dp[i - ci];

			}
			dp[i] = 1 + min;
		}
		return dp[amount] > 1 + amount ? -1 : dp[amount];
	}
};

class Solution {		//myslf2
public:
	int coinChange(vector<int>& coins, int amount) {
		vector<int> dp(amount + 1, amount + 1);
		dp[0] = 0;
		for (int i = 1; i <= amount; i++) {
			int min = amount + 1;
			for (auto ci : coins) {
				if (i < ci)
					continue;
				if (min > dp[i - ci])
					min = dp[i - ci];

			}
			dp[i] = 1 + min;
		}
		return dp[amount] > 1 + amount ? -1 : dp[amount];
	}
};