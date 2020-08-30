#include <iostream>
#include<stack>
#include<vector>
#include<cmath>
using namespace std;

int numSubarrayProductLessThanK(vector<int>& nums, int k) {	//˫ָ�뷨

	if (nums.size() == 0)
		return 0;
	size_t len = nums.size();

	int res = 0;
	size_t left = 0;
	long long mul = 1;
	for (size_t right = 0; right < len; right++)
	{
		mul *= nums[right];

		while ( mul >= k) //���ڲų�
				mul /= nums[left++]; 
		
		res += right - left + 1;  //С��ֱ�Ӽ���

	}
	return res;
}