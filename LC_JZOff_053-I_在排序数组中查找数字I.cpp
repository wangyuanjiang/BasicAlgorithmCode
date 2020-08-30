#include "JZOff.h"

/*ͳ��һ�����������������г��ֵĴ�����*/

class Solution { //myself ���ֲ��� 
public:
	int search(vector<int>& nums, int target) {

		if (nums.empty()) return 0;
		int right = nums.size() - 1;
		int left = 0;
		int  mid = left + (right - left) / 2;
		int cnt = 0;
		bool flag = false;
		while (left <= right) //ע�⣡����������������������
		{
			mid = left + ((right - left) >> 1); 
			if (nums[mid] > target)  right = mid - 1; //ע��д��right = mid  �ᳬʱ������������������

			else if (nums[mid] < target) left = mid + 1;//ע��д��left = mid  �ᳬʱ������������������

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

class Solution {  //stl find��������
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