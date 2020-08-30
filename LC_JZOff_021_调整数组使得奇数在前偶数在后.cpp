#include "JZOff.h"

class solution
{
public:

	//    1�� ˫ָ��
	vector<int> exchange(vector<int>& nums) {

		if (nums.size() <= 1)	return nums;

		int left = 0, right = nums.size();

		while (left < right )
		{
			/*if ((nums[left] & 1) != 0)	//����ʱ left++
			{
				left++;
				continue;						//�������while���ȼ�
			}

			if ((nums[right] & 1) == 0)	//ż���� right --��
			{
				right--;
				continue;
			}*/

			while (left < right && (nums[left] & 1) != 0)  left++; //�����while�����ﲻ���� left< right ���ò�����ȷ�Ľ����

			while (left < right && (nums[right] & 1) == 0)	right--;
			
			swap(nums[left], nums[right]);
		}
		return nums;
	}



};


/*    �ⷨ2 �� ����˫ָ��
�������˫ָ�� fastfast �� lowlow ��fastfast ��ǰ�� lowlow �ں� .
fastfast ����������ǰ��������λ�ã�lowlow ��������ָ����һ������Ӧ����ŵ�λ��
fastfast ��ǰ�ƶ�����������������ʱ�������� nums[low]nums[low] ��������ʱ low ��ǰ�ƶ�һ��λ�� .
�ظ�����������ֱ�� fast ָ������ĩβ .
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

/*  �ⷨ3  ���Ʋ�������      �ᳬʱ*/

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