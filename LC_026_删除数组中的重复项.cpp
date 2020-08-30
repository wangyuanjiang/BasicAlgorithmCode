
#include <iostream>

#include <vector>

using namespace std;
/*����һ���������飬����Ҫ�� ԭ�� ɾ���ظ����ֵ�Ԫ�أ�ʹ��ÿ��Ԫ��ֻ����һ�Σ������Ƴ���������³��ȡ�

��Ҫʹ�ö��������ռ䣬������� ԭ�� �޸��������� ����ʹ�� O(1) ����ռ����������ɡ�

*/

class Solution {	//˫ָ��
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

	int removeDuplicates(vector<int>& nums) {  //����erase
	
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