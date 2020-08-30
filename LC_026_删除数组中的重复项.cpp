
#include <iostream>

#include <vector>

using namespace std;
/*给定一个排序数组，你需要在 原地 删除重复出现的元素，使得每个元素只出现一次，返回移除后数组的新长度。

不要使用额外的数组空间，你必须在 原地 修改输入数组 并在使用 O(1) 额外空间的条件下完成。

*/

class Solution {	//双指针
public:
	int removeDuplicates(vector<int>& nums) {

		int left = 0;
		int right = left + 1;

		if (nums.size() <= 1) return nums.size();

		for (; right < nums.size(); right++)
		{
			if (nums[right] != nums[left])
			{
				left++;
				nums[left] = nums[right];

			}

		}

		return left + 1;
	}
};

class solution {

	int removeDuplicates(vector<int>& nums) {  //暴力erase
	
		int i = 1;
		for (; i < nums.size(); i++)
		{
			if (nums[i] == nums[i - 1]) {
				i--;
				nums.erase(nums.begin() + i);
			}
		}
		return nums.size();
	}

};