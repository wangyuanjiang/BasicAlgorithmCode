
#include "JZOff.h"

//��Ŀ������ţ������̫һ���������ԭ�ַ�����ǰ�˺�ĩ�˻��пո� ���ǽ��Ҫ��ȥ��ǰ��˵Ŀո�

class Solution {//������vector��
public:
	string reverseWords(string str) {

		if (str.empty())
			return "";
		string res = "", tmp = "";
		str.erase(0, str.find_first_not_of(' '));	//�����ַ���ǰ��Ŀո�
		str.erase(str.find_last_not_of(' ') + 1);	//�����ַ�������Ŀո�

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