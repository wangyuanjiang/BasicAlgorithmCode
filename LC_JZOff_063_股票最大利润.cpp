#include "JZOff.h"
/*�����ĳ��Ʊ�ļ۸���ʱ���Ⱥ�˳��洢�������У����������ù�Ʊһ�ο��ܻ�õ���������Ƕ��٣�*/

class Solution {	// mysel ��̬�滮
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

class Solution {  //myslfe ��һ���������С�۸� һ��������������
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