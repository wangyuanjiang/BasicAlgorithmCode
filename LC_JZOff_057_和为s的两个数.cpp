#include "JZOff.h"

class Solution { //˫ָ�룬 ��Ϊ��Ŀ˵���������� ��
public:
	vector<int> twoSum(vector<int>& nums, int target) {

		vector<int> v(2);

		int left = 0;
		int right = (int)(nums.size() - 1);

		while (left < right)
		{
			int diff = target - nums.at(right); //��͸�Ϊ����ֹ���
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




class Solution { //MAP �����������Ҳ���ԣ�
public:
	vector<int> twoSum(vector<int>& nums, int target) {

		map<int, int> map1;
		vector<int> res;
		size_t i;
		for (i = 0; i < nums.size(); ++i) {
			map1[nums[i]] = i;//key Ϊnums[i],value ��ֵΪ �±ꣻ
		}
		for (i = 0; i < nums.size(); ++i) {
			int v = target - nums[i];
			if (map1.count(v) && map1[v] != i) {//�����Ҳ��Ǳ���
				res.push_back(i);
				res.push_back(map1[v]);
			}
		}
		return res;
	}

};

