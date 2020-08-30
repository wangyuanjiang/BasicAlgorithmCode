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
		dp[i] = max(nums[i], dp[i - 1] + nums[i]);	//dp[i],��nums[i]��β�������
		if (max1 < dp[i])
			max1 = dp[i];
	}

	/*for (size_t i = 1; i < len; i++)
		if (max < dp[i])
			max = dp[i];*/
	return max1;
}

//////////////////////���η�////////////////////////////////////////
//�Ƚ����ҡ��м������ֵ����к͵Ĵ�С����Ϊ�м䲿����û�취���εģ�ֻ����ÿһ��ݹ麯���ռ��������,���Եݹ�Ĳ���Ϊ���ң�
//�������Ҳ������к��зֱ�Ϊ�β�ݹ�Ľ�����ݹ�����ı�־������Ϊ��ͬλ��Ԫ�أ���ֻ��һ��Ԫ��. 

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
		//�����ǰ����ֻ��һ��Ԫ��
		return data[left];
	}
	int center = (left + right) / 2;//���㵱ǰ���еķ��ѵ�

	int maxLeftSum = maxSumRec(data, left, center);//�ݹ�
	int maxRightSum = maxSumRec(data, center, right);//�ݹ�

	//������߽���������к�
	int leftBonderSum = 0;
	int maxLeftBonderSum = data[center - 1];
	for (int i = center - 1; i >= left; i--) {
		leftBonderSum += data[i];
		if (maxLeftBonderSum < leftBonderSum) {
			maxLeftBonderSum = leftBonderSum;
		}
	}
	//�����ұ߽���������к�
	int rightBonderSum = 0;
	int maxRightBonderSum = data[center];
	for (int i = center; i < right; i++) {
		rightBonderSum += data[i];
		if (maxRightBonderSum < rightBonderSum) {
			maxRightBonderSum = rightBonderSum;
		}
	}
	//���ص�ǰ������������к�
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