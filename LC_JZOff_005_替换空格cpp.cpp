
#include "JZOff.h"


class Solution {  //解法1， 该解法比解法2快许多
public:
	string replaceSpace(string s) {

		string res;

		for (auto ix : s)
		{
			if (ix == ' ')
				res += "%20";
			else
				res += ix;

		}

		return res;
	}
};

class Solution { //解法2
public:
	string replaceSpace(string s) {

		string res;

		for (int i = 0; i < s.size(); i++)
		{
			if (s[i] == ' ')
				res += "%20";
			else
				res.push_back(s[i]);

		}

		return res;
	}
};