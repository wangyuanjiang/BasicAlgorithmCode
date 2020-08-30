
#include "JZOff.h"

class Solution {
public:
	string minNumber(vector<int>& nums) {

		sort(nums.begin(), nums.end(), cmp);
		string str;
		for (auto ix : nums)
			str += to_string(ix);
		return str;

	}
	static bool cmp(int a, int b) {  //��������Ϊstatic ��Ȼ�ᱨ��

		string s1 = to_string(a) + to_string(b);
		string s2 = to_string(b) + to_string(a);

		return s1 < s2;	//���Ҫ�ų���� �� < ���� > ����
		
	}
};

class Solution {	/*������ͬ����˼�룬ֻ�����Ѵ������������� lambda*/
public:
	string minNumber(vector<int>& nums) {

		sort(nums.begin(), nums.end(), [](int& a, int& b) {return to_string(a) + to_string(b) < to_string(b) + to_string(a); });

		string str;
		for (auto ix : nums)
			str += to_string(ix);
		return str;

	}
	
};