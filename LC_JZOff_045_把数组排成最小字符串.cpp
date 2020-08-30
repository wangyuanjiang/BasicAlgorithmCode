
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
	static bool cmp(int a, int b) {  //必须申明为static 不然会报错

		string s1 = to_string(a) + to_string(b);
		string s2 = to_string(b) + to_string(a);

		return s1 < s2;	//如果要排成最大， 将 < 换成 > 即可
		
	}
};

class Solution {	/*和上面同样的思想，只不过把触摸屏函数换成 lambda*/
public:
	string minNumber(vector<int>& nums) {

		sort(nums.begin(), nums.end(), [](int& a, int& b) {return to_string(a) + to_string(b) < to_string(b) + to_string(a); });

		string str;
		for (auto ix : nums)
			str += to_string(ix);
		return str;

	}
	
};