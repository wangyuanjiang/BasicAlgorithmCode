
#include "JZOff.h"

//题目条件和牛客网不太一样，这里的原字符串的前端和末端会有空格， 但是结果要求去掉前后端的空格

class Solution {//不借助vector，
public:
	string reverseWords(string str) {

		if (str.empty())
			return "";
		string res = "", tmp = "";
		str.erase(0, str.find_first_not_of(' '));	//处理字符串前面的空格
		str.erase(str.find_last_not_of(' ') + 1);	//处理字符串后面的空格

		for (int i = 0; i < str.size(); i++) {

			if (str[i] == ' ' && tmp != "") {
				res = ' ' + tmp + res;
				tmp = "";
			}
			else if (str[i] == ' ' && tmp == "")

				continue;
			else
			{
				tmp += str[i];
			}
		}

		if (tmp != "") res = tmp + res;

		return res;
	}
};

class Solution {
public:
	string reverseWords(string str) {

		//string str;
		if (str.size() == 0)
			return "";


		/*int begin = 0, end = s.size() - 1;

		while (begin < s.size())
		{
			if (s[begin] == ' ')
				begin++;
			else
				break;
		}
		while (end >= 0)
		{
			if (s[end] == ' ')
				end--;
			else
				break;
		}
		str = s.substr(begin, end - begin + 1);*/
		str.erase(0, str.find_first_not_of(' '));
		str.erase(str.find_last_not_of(' ') + 1);


		vector<string> vec;
		string tem;
		for (int i = 0; i < str.size(); i++)
		{
			if (str[i] != ' ')
			{
				tem += str[i];
			}
			if (str[i] == ' ' && !tem.empty())
			{
				vec.push_back(tem);
				tem.clear();
			}
			if (str[i] == ' ' && tem.empty()) continue;

		}
		if (!tem.empty())
			vec.push_back(tem);

		string res;
		if (!vec.empty()) {

			for (int i = vec.size() - 1; i > 0; i--)
			{
				res += vec[i];
				res += ' ';
			}
			res += vec[0];
		}

		return res;

	}
};