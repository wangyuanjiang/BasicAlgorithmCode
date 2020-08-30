#include "JZOff.h"

class Solution { //双指针， 因为题目说数组是有序 的
public:
	vector<int> twoSum(vector<int>& nums, int target) {

		vector<int> v(2);

		int left = 0;
		int right = (int)(nums.size() - 1);

		while (left < right)
		{
			int diff = target - nums.at(right); //求和改为求差，防止溢出
			if (diff == nums.at(left))
			{
				v.at(0) = nums.at(left);
				v.at(1) = nums.at(right);
				break;
			}
			else if (diff > nums.at(left))
			{
				++left;
			}
			else
			{
				--right;
			}
		}

		return v;
	}

};




class Solution { //MAP 数组是无序的也可以；
public:
	vector<int> twoSum(vector<int>& nums, int target) {

		map<int, int> map1;
		vector<int> res;
		size_t i;
		for (i = 0; i < nums.size(); ++i) {
			map1[nums[i]] = i;//key 为nums[i],value 的值为 下标；
		}
		for (i = 0; i < nums.size(); ++i) {
			int v = target - nums[i];
			if (map1.count(v) && map1[v] != i) {//存在且不是本身
				res.push_back(i);
				res.push_back(map1[v]);
			}
		}
		return res;
	}

};

