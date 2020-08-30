#include<iostream>
//include<algorithm>
#include<vector>
using namespace std;

/*设计一个算法来计算你所能获取的最大利润。你可以尽可能地完成更多的交易（多次买卖一支股票）。

注意：你不能同时参与多笔交易（你必须在再次购买前出售掉之前的股票）。*/


//-------------------------暴力法-------------------
class Solution {
public:
	int maxProfit(vector<int>& prices) {
		return calculate(prices, 0);
	}

	int calculate(vector<int>& prices, int s) {
		if (s >= prices.size())
			return 0;
		int max = 0;
		for (int start = s; start < prices.size(); start++) {
			int maxprofit = 0;
			for (int i = start + 1; i < prices.size(); i++) {
				if (prices[start] < prices[i]) {
					int profit = calculate(prices, i + 1) + prices[i] - prices[start];// 递归n^n 次 复杂度为O(n^n)
					if (profit > maxprofit)
						maxprofit = profit;
				}
			}
			if (maxprofit > max)
				max = maxprofit;
		}
		return max;
	}


};

//--------------------峰谷法---关键是我们需要考虑到紧跟谷的每一个峰值以最大化利润。如果我们试图跳过其中一个峰值来获取更多利润，
//                            那么我们最终将失去其中一笔交易中获得的利润，从而导致总利润的降低。

class Solution {
public: int maxProfit(vector<int>& prices) {
		int i = 0;
		int valley = prices[0];
		int peak = prices[0];
		int maxprofit = 0;
		while (i < prices.size() - 1) {
			while (i < prices.size() - 1 && prices[i] >= prices[i + 1])
				i++;
			valley = prices[i]; // 谷
			while (i < prices.size()- 1 && prices[i] <= prices[i + 1])
				i++;
			peak = prices[i];	//峰
			maxprofit += peak - valley;
		}
		return maxprofit;
	}
};

//--------------------------简单一次遍历
// 1 5 7 8 profit= 5-1+ 7-5+ 8-7 = 8-1 =7; 只要后面一个比前面一个大就计算差值
int maxProfit(vector<int>& prices) {
	int totalProfite = 0;
	for (size_t i = 1; i < prices.size(); i++)
	{
		if (prices[i - 1] < prices[i])
			totalProfite += (prices[i] - prices[i - 1]);
	}
	return totalProfite;
}


