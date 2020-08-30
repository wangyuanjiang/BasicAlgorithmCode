#include "JZOff.h"


//注意 数值的前面和后面都可以有空格，中间不能有， .1也是数值， 1.也是数值
class Solution {
public:
	bool isNumber(string s) {

		int len = s.size();

		if (len == 0)    return false;

		int point = 0, num = 0, nume = 0, i = 0;

		while (s[i] == ' ' && i < len) {	//除掉前端的空格
			i++;
		}
		if (i > len - 1)    return false;	//如果从前面开始全是空格
		while (s[len - 1] == ' ')	//除掉后端的空格
			len--;

		if (len == 0)   return false;	//如果从后面开始也全是空格

		if (s[i] == '+' || s[i] == '-')
			i++;

		if (i > len - 1)    return false;



		while (i < len)
		{
			if (s[i] >= '0'  && s[i] <= '9')
			{
				i++;
				num = 1;
			}

			else if (s[i] == '.') {
				if (point == 1 || nume == 1)   return false;

				i++;
				point = 1;
				if (num == 0 && i > len - 1)   return false;	//只有点的情况
			}

			else if (s[i] == 'E' || s[i] == 'e')
			{
				if (nume == 1 || num == 0)    return false;	//有多个e或者e之前没有数字的情况

				i++;
				nume = 1;
				if (i < len && (s[i] == '+' || s[i] == '-'))	//e之后紧跟着+ -；
					i++;

				if (i > len - 1) return false;	//e之后没有数字的情况
			}
			/*else if (s[i] == ' ')
			{
				i++;

				if (i < len  && s[i] != ' ')
					return false;
			}*/
			else {
				return false;
			}
		}
		return true;


	}
};