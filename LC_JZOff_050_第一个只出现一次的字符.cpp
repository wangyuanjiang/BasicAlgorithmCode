#include "JZOff.h"

class Solution {
public:
	char firstUniqChar(string s) {  //map 错误的
		unordered_map<char, int> mp;

		if (s == "") return ' ';

		for (int i = 0; i < s.size(); i++)
		{
			mp.insert(pair<char, int >(s[i], 0));
		}
		for (int i = 0; i < s.size(); i++)
		{
			mp[s[i]] ++;
		}

		auto it = mp.begin();
		for (; it != mp.end(); it++) {

			if (it->second == 1);
			break;
		}
		return it->first;
	}
};

class Solution {	//map 正确的
public:
char firstUniqChar(string s) {
	if (s == "")
		return ' ';
	//map中是对应字符出现的次数
	unordered_map<char, int> cmap;
	for (auto i = 0; i < s.size(); i++)
	{
		cmap[s[i]]++;
	}
	//按字符串的顺序在map中查找到第一个出现一次的字符
	for (auto i = 0; i < s.size(); i++)  //！！！！！！！！！！！！！！,注意要用这种遍历方式
	{
		if (cmap[s[i]] == 1)
			return s[i];
	}
	//没有找到
	return ' ';
}
};

class Solution {		//不用map，
public:
	char firstUniqChar(string s) {
		vector<int> d(128, 0);
		int i = 0, j = 0;
		for (int i = 0; i < s.length(); i++) {
			d[s[i]]++;
			while (d[s[j]] > 1)j++;
		}
		if (j < s.length())return s[j];
		return ' ';
	}
};

