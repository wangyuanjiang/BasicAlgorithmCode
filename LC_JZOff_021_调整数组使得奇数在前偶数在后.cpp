#include "JZOff.h"

class solution
{
public:

	//    1， 双指针
	vector<int> exchange(vector<int>& nums) {

		if (nums.size() <= 1)	return nums;

		int left = 0, right = nums.size();

		while (left < right )
		{
			/*if ((nums[left] & 1) != 0)	//奇数时 left++
			{
				left++;
				continue;						//和下面的while语句等价
			}

			if ((nums[right] & 1) == 0)	//偶数是 right --；
			{
				right--;
				continue;
			}*/

			while (left < right && (nums[left] & 1) != 0)  left++; //如果在while条件里不加上 left< right 将得不到正确的结果；

			while (left < right && (nums[right] & 1) == 0)	right--;
			
			swap(nums[left], nums[right]);
		}
		return nums;
	}



};


/*    解法2 ： 快慢双指针
定义快慢双指针 fastfast 和 lowlow ，fastfast 在前， lowlow 在后 .
fastfast 的作用是向前搜索奇数位置，lowlow 的作用是指向下一个奇数应当存放的位置
fastfast 向前移动，当它搜索到奇数时，将它和 nums[low]nums[low] 交换，此时 low 向前移动一个位置 .
重复上述操作，直到 fast 指向数组末尾 .
*/

class Solution {
public:
	vector<int> exchange(vector<int>& nums) {
		
		if (nums.size() <= 1)	return	nums;

		int slow = 0, fast = 0;
		
		while (fast < nums.size())
		{
			if ((nums[fast] & 1) == 0)
			{
				swap(nums[slow], nums[fast]);
				slow++;
			}

			fast++;
		}

		return nums;
	}
};

/*  解法3  类似插入排序      会超时*/

class Solution {

public:

	vector<int> exchange(vector<int>& nums) {

		if (nums.size() <= 1)	return	nums;

		for (int i = 0; i < nums.size(); i++)
		{
			if ((nums[i] & 1) != 0)
			{
				for (int j = i - 1; j >= 0; j--)
				{
					if ((nums[i] & 1) != 0)
						break;

					swap(nums[j + 1], nums[j]);
				}
			
			}
		}

		return nums;
	}
};

class Solution {

	vector<int> insertSort(vector<int>& nums) {

		if (nums.size() <= 1)	return	nums;

		for (int i = 1; i < nums.size(); i++)
		{
			if (nums[i] < nums[i - 1])
			{
				for (int j = i-1; j >= 0; j--) {
				
					if (nums[j + 1] > nums[j])
						break;
					swap(nums[j + 1], nums[j]);
				}
			}
		}

		return nums;
	}
	
};