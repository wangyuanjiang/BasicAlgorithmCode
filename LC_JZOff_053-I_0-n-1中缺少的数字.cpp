#include "JZOff.h"

/*一个长度为n - 1的递增排序数组中的所有数字都是唯一的，并且每个数字都在范围0～n - 1之内
。在范围0～n - 1内的n个数字中有且只有一个数字不在该数组中，请找出这个数字。*/

/*初始化： 左边界 i = 0 ，右边界 j = len(nums) - 1；代表闭区间[i, j] 。
循环二分： 当 i≤j 时循环 （即当闭区间[i, j] 为空时跳出） ；
计算中点 m = (i + j) / 2 ，
若 nums[m] = m ，则 “右子数组的首位元素” 一定在闭区间[m + 1, j 中，因此执行 i = m + 1
 nums[m] !=m，则 “左子数组的末位元素” 一定在闭区间[i, m - 1] 中，因此执行 j = m - 1；
返回值： 跳出时，变量 i 和 j 分别指向 “右子数组的首位元素” 和 “左子数组的末位元素” 。因此返回 i 即可。

*/

class Solution {	//二分查找
public:
	int missingNumber(vector<int>& nums) {

		if (nums.size() == 1)
			return nums[0] == 0 ? 1 : 0;
		int left = 0, right = nums.size() - 1, mid;
		while (left <= right)
		{
			mid = left + (right - left) / 2;

			if (nums[mid] == mid)    left = mid + 1;
			else    right = mid - 1;
		}

		return left;
	}
};

class Solution {		//遍历
public:
	int missingNumber(vector<int>& nums) {

		if (nums.size() == 1)
			return nums[0] == 0 ? 1 : 0;
		for (int i = 0; i < nums.size(); i++)
		{
			if (nums[i] != i)
				return i;
		}

		return nums[0] == 0 ? nums.size() : 0;
	}
};