#include "JZOff.h"
/*假设把某股票的价格按照时间先后顺序存储在数组中，请问买卖该股票一次可能获得的最大利润是多少？*/

class Solution {	// mysel 动态规划
public:
	int maxProfit(vector<int>& prices) {
		vector<int>dp(prices.size(), 0);
		int max = 0;
		for (int i = 1; i < prices.size(); i++)
		{
			int diff = prices[i] - prices[i - 1];
			dp[i] = dp[i - 1] + diff > 0 ? dp[i - 1] + diff : 0;

			if (max < dp[i])
				max = dp[i];
		}

		return max;
	}
};

class Solution {  //myslfe 用一个数标记最小价格， 一个数标记最大利润
public:
	int maxProfit(vector<int>& prices) {
		if (prices.empty())   return 0;
		int min = prices[0];
		int max_profit = 0;

		for (int i = 1; i < prices.size(); i++)
		{
			/* if(min > prices[i])
				min = prices[i];

			 if(max_profit < prices[i] - min)
			  max_profit = prices[i] - min ;
		  */

			min = min > prices[i] ? prices[i] : min;

			max_profit = max_profit < prices[i] - min ? prices[i] - min : max_profit;
		}

		return max_profit;
	}
};