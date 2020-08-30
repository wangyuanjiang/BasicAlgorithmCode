#include "JZOff.h"




class Solution {	//别人的方法，
public:
	int strToInt(string str) {
		if (str.size() == 0) return 0;
		int i = 0;
		long ans = 0;
		bool negative = false;

		//跳过前面空格，判断正负
		while (str[i] == ' ') i++;
		if (str[i] == '-')
		{
			negative = true;
			i++;
		}
		else if (str[i] == '+')
			i++;

		//对非空和非+-号的有效数字进行处理
		for (; i < str.size(); i++)
		{
			if (str[i] >= '0' && str[i] <= '9')  //判断是否为有效数字
			{
				ans = ans * 10 + (str[i] - '0');  //***字符相减转换成int
				if (ans > INT_MAX && negative) return INT_MIN;
				if (ans > INT_MAX && !negative) return INT_MAX;
			}
			else        //碰到非有效数字就退出
				break;
		}

		return negative ? -ans : ans;
	}
};

class Solution {	//myself
public:
	int strToInt(string str) {

		int flag;
		int value = 0;
		if ('0' <= str[0] && str[0] <= '9')
			flag = 1;
		else if (str[0] == '-' || str[0] == '+')
			flag = 2;

		else if (str[0] == ' ')
			flag = -1;
		else
			flag = 0;
		//size_t i = 0;
		string::size_type i = 0;
		std::string s1;
		if (flag == 1)
			while (1) {
				s1.push_back(str[i]);
				i++;

				if (!('0' <= str[i] && str[i] <= '9')) {

					break;
				}
			}

		if (flag == 2) {
			if (('0' <= str[1] && str[1] <= '9')) {
				s1.push_back(str[0]);
				i = 1;
				while (1) {


					if (('0' <= str[i] && str[i] <= '9')) {
						s1.push_back(str[i]);
						i++;
					}
					if (!('0' <= str[i] && str[i] <= '9')) {

						break;
					}
				}
			}
			else

				value = 0;
		}
		if (flag == -1)
			while (1) {
				if (str[i] == ' ')
					i++;
				else if (str[i] == '-' || str[i] == '+') {
					if ('0' <= str[i + 1] && str[i + 1] <= '9') {
						s1.push_back(str[i]);
						i++;
					}
					else {

						value = 0;
						break;
					}
				}
				else if (('0' <= str[i] && str[i] <= '9')) {
					s1.push_back(str[i]);
					i++;
					if (!('0' <= str[i] && str[i] <= '9')) {

						break;
					}
				}

				else {

					value = 0;
					break;
				}
			}
		if (flag == 0)

			value = 0;

		if (s1.size() > 0)  //
		{
			istringstream is;  //字符串转数字的库函数，自动判断是否越界，并且忽略第一个非0数字前面的所有0，如果>INT32_MAX, 则返回INT32_MAX，如果小于INT_MIN,则返回INT_MIN
			is.str(s1);
			is >> value;
		}

		return value;
	}
};
