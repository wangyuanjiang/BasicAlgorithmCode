#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int maxSubArray(vector<int>& nums) {
	size_t len = nums.size();
	vector<int> dp(len, 0);
	dp[0] = nums[0];
	int max1 = dp[0];
	for (size_t i = 1; i < len; i++) {
		dp[i] = max(nums[i], dp[i - 1] + nums[i]);	//dp[i],以nums[i]结尾的子序和
		if (max1 < dp[i])
			max1 = dp[i];
	}

	/*for (size_t i = 1; i < len; i++)
		if (max < dp[i])
			max = dp[i];*/
	return max1;
}

//////////////////////分治法////////////////////////////////////////
//比较左、右、中间三部分的序列和的大小，因为中间部分是没办法分治的，只能在每一层递归函数空间里面进行,所以递归的部分为左、右，
//而且左右部分序列和有分别为次层递归的结果。递归结束的标志：左右为相同位置元素，即只有一个元素. 

int getMaxNum(int a, int b, int c) {
	if (a > b&&a > c) {
		return a;
	}
	if (b > a&&b > c) {
		return b;
	}
	return c;
}
int maxSumRec(int data[], int left, int right) {
	if (right - left == 1) {
		//如果当前序列只有一个元素
		return data[left];
	}
	int center = (left + right) / 2;//计算当前序列的分裂点

	int maxLeftSum = maxSumRec(data, left, center);//递归
	int maxRightSum = maxSumRec(data, center, right);//递归

	//计算左边界最大子序列和
	int leftBonderSum = 0;
	int maxLeftBonderSum = data[center - 1];
	for (int i = center - 1; i >= left; i--) {
		leftBonderSum += data[i];
		if (maxLeftBonderSum < leftBonderSum) {
			maxLeftBonderSum = leftBonderSum;
		}
	}
	//计算右边界最大子序列和
	int rightBonderSum = 0;
	int maxRightBonderSum = data[center];
	for (int i = center; i < right; i++) {
		rightBonderSum += data[i];
		if (maxRightBonderSum < rightBonderSum) {
			maxRightBonderSum = rightBonderSum;
		}
	}
	//返回当前序列最大子序列和
	return getMaxNum(maxLeftBonderSum + maxRightBonderSum, maxLeftSum, maxRightSum);
}

int maxProfit(vector<int>& prices) {
	//vector<int>a(*prices.size(),*prices);
	vector<int>& a = prices;

	vector<int> dp(prices.size(),0);
	dp[0] = 0;
	int max = 0;
	for (size_t i = prices.size() - 1; i > 0; i--) {
		if (a[i] >= a[i - 1])
			dp[i] = dp[i - 1] + a[i] - a[i - 1];
		if (a[i] < a[i - 1]) {
			dp[i] = dp[i - 1];
			a[i] = a[i - 1];
		}
		if (max < dp[i]) {
			max = dp[i];
		}
		return max;
	}
}