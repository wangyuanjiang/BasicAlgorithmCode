#include "JZOff.h"

/*统计一个数字在排序数组中出现的次数。*/

class Solution { //myself 二分查找 
public:
	int search(vector<int>& nums, int target) {

		if (nums.empty()) return 0;
		int right = nums.size() - 1;
		int left = 0;
		int  mid = left + (right - left) / 2;
		int cnt = 0;
		bool flag = false;
		while (left <= right) //注意！！！！！！！！！！！！
		{
			mid = left + ((right - left) >> 1); 
			if (nums[mid] > target)  right = mid - 1; //注意写成right = mid  会超时！！！！！！！！！

			else if (nums[mid] < target) left = mid + 1;//注意写成left = mid  会超时！！！！！！！！！

			else {
				flag = true;
				break;
			}
		}

		if (flag)
		{
			cnt++;
			right = mid + 1;
			left = mid - 1;
			while (right < nums.size() && nums[right] == target)
			{
				cnt++;
				right++;
			}
			while (left >= 0 && nums[left] == target)
			{
				cnt++;
				left--;
			}
		}

		return cnt;
	}
};

class Solution {  //stl find（）函数
public:
	int search(vector<int>& nums, int target) {

		if (nums.empty()) return 0;
		int cnt = 0;

		auto it = find(nums.begin(), nums.end(), target);

		if (it == nums.end())    return 0;

		while (it != nums.end() && *it == target)
		{
			cnt++;
			it++;
		}

		return cnt;
	}
};

class Solution {	// upper_bound
public:
	int search(vector<int>& nums, int target) {
		return upper_bound(nums.begin(), nums.end(), target) - lower_bound(nums.begin(), nums.end(), target);
	}
};