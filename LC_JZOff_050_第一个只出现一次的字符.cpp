#include "JZOff.h"

class Solution {
public:
	char firstUniqChar(string s) {  //map �����
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

class Solution {	//map ��ȷ��
public:
char firstUniqChar(string s) {
	if (s == "")
		return ' ';
	//map���Ƕ�Ӧ�ַ����ֵĴ���
	unordered_map<char, int> cmap;
	for (auto i = 0; i < s.size(); i++)
	{
		cmap[s[i]]++;
	}
	//���ַ�����˳����map�в��ҵ���һ������һ�ε��ַ�
	for (auto i = 0; i < s.size(); i++)  //����������������������������,ע��Ҫ�����ֱ�����ʽ
	{
		if (cmap[s[i]] == 1)
			return s[i];
	}
	//û���ҵ�
	return ' ';
}
};

class Solution {		//����map��
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

