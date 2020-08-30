#include<iostream>
#include<algorithm>
#include<vector>
#include<map>
#include<string>
using namespace std;
class Solution {
public:
	int romanToInt(string s) {
		int a = 0;
		size_t len = s.size();
		for (size_t i = 0; i < s.size(); i++) {
			if (s[i] == 'M')
				a = a + 1000;
			if (s[i] == 'D')
				a = a + 500;
			if (s[i] == 'C') {
				if (i + 1 < len && (s[i + 1] == 'D' || s[i + 1] == 'M'))
					a = a - 100;
				else
					a = a + 100;
			}
			if (s[i] == 'L')
				a = a + 50;
			if (s[i] == 'X') {
				if (i + 1 < len && (s[i + 1] == 'L' || s[i + 1] == 'C'))
					a = a - 10;
				else
					a = a + 10;
			}
			if (s[i] == 'V')
				a = a + 5;
			if (s[i] == 'I') {
				if (i + 1 < len && (s[i + 1] == 'V' || s[i + 1] == 'X'))
					a = a - 1;
				else
					a = a + 1;
			}
		}
		return a;
	}

	
		int romanToInt1(string s) {
			int result = 0;//存放结果
			map<char, int> luomab;//建立罗马表
			//插入对应关系
			luomab.insert(map<char, int>::value_type('I', 1));
			luomab.insert(map<char, int>::value_type('V', 5));
			luomab.insert(map<char, int>::value_type('X', 10));
			luomab.insert(map<char, int>::value_type('L', 50));
			luomab.insert(map<char, int>::value_type('C', 100));
			luomab.insert(map<char, int>::value_type('D', 500));
			luomab.insert(map<char, int>::value_type('M', 1000));
			for (int i = 0; i < s.length(); i++)
			{
				if (luomab[s[i]] >= luomab[s[i + 1]])
					result += luomab[s[i]];
				else
				{
					result += (luomab[s[i + 1]] - luomab[s[i]]);
					i++;
				}
			}
			return result;
		}
	

};
