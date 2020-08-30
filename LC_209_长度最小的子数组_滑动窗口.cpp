
#include <iostream>
#include<vector>
#include <algorithm>
#include <queue>
using namespace std;
/*给定一个含有 n 个正整数的数组和一个正整数 s ，找出该数组中满足其和 ≥ s 的长度最小的连续子数组的长度。
如果不存在符合条件的连续子数组，返回 0。*/

class Solution {	//myself
public:
	int minSubArrayLen(int s, vector<int>& nums) {

		if (nums.empty())    return 0;
		deque<int> que;
		int res = nums.size(), sum = 0;
		bool flag = false;
		for (int i = 0; i < nums.size(); i++) {

			//if(sum < s){
			que.push_back(nums[i]);
			sum += nums[i];
			//}

			while (!que.empty() && sum - que.front() >= s) {
				sum = sum - que.front();
				que.pop_front();

			}

			if (sum >= s) {
				flag = true;
				if (res > que.size())
					res = que.size();
			}

		}

		return (flag ? res : 0);
	}

};

/*
1开始right向右滑动，使和变大。
2当恰好大于等于s时，记录滑窗所包括的子数组长度res，
	若res已有数值，需判断新值是否小于旧值，若是，更新res。i 向右滑动
3判断是否仍大于等于s
若是，重复步骤2，3。若否，转步骤1。直到右边框到达最右边

*/
class Solution {  //别人的
public:
	int minSubArrayLen(int s, vector<int>& nums) {
		if (nums.empty()) return 0;
		int res = nums.size() + 1;
		int i = 0, right = 0, sum = 0;
		while (right < nums.size())	 //滑窗的右边框不能超出界限
		{
			if (sum + nums[right] < s) {	//若滑窗之间的和小于s，右边框右移，sum增大
				sum += nums[right];
				right++;
			}


			else {						//若滑窗之间的和大于等于s，左边框右移，sum减小
				if (res > right - i)  res = right - i + 1;	//若当前符合条件的连续子数组比res内记录的长度更小，则更新res值

				sum -= nums[i];
				i++;
			}
		}
		return (res > nums.size() ? 0 : res);	//需要判断是否存在
	}

};


class Solution {  //双指针
public:
	int minSubArrayLen(int s, vector<int>& nums) {

		int res = nums.size() + 1;
		int left = 0;
		int sum = 0;
		for (int i = 0; i < nums.size(); i++) {
		
			sum += nums[i];
			while (sum >=s)
			{
				res = min(res, i - left + 1);
				sum -= nums[left++];
			}
		}

		return (res > nums.size() ? 0 : res);
	}
};