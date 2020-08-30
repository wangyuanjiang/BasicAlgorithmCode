#include<iostream>
//include<algorithm>
#include<vector>
using namespace std;

    int maxProfit(vector<int>& prices) {
	//vector<int>a(*prices.size(),*prices);
        if(prices.size()<=1)
            return 0;
	vector<int> a = prices;
	vector<int> dp(prices.size(), 0);//de table
	dp[0] = 0;
	int max = 0;
	for (size_t i =1; i <prices.size(); i++) {
		
		if (a[i] <= a[i - 1]) {
			dp[i] = dp[i - 1];
	
		}
        if (a[i] > a[i - 1])
        {
			dp[i] = a[i] - a[i-1];
            a[i]=a[i-1];  // 记录小的那个
        }
		if (max < dp[i]) { 
			max = dp[i];
		}
		
	}
	return max;
}
	int maxProfit1(vector<int>& prices) {
		//vector<int>a(*prices.size(),*prices);
		if (prices.size() <= 1)
			return 0;
		vector<int> a = prices;
		int maxProfit = 0;
		int minPrice = a[0];//用一个数记录价格最小值，用一个数记录利润最大值
			for (size_t i = 1; i < prices.size(); i++) {
			if (minPrice > a[i])
				minPrice = a[i];
			if (maxProfit < a[i] - minPrice)
				maxProfit = a[i] - minPrice;
		}
		return maxProfit;
	}

