#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int maxSubArray(vector<int>& nums) {
	size_t len = nums.size();
	vector<int> dp(len, 0);
	dp[0] = nums[0];
	for (size_t i = 1; i < len; i++)
		dp[i] = max(nums[i], dp[i - 1] + nums[i]);
	int max = dp[0];
	for (size_t i = 1; i < len; i++)
		if (max < dp[i])
			max = dp[i];
	return max;
}
int mainLC_053() {
	vector<int> nums;
	cout << "please entry nums" << endl;
	int x;
	while (cin >> x)
		nums.push_back(x);
	cout << " the maxSubArray is " << maxSubArray(nums) << endl;
	return 0;
}