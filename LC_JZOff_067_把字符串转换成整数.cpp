#include "JZOff.h"




class Solution {	//���˵ķ�����
public:
	int strToInt(string str) {
		if (str.size() == 0) return 0;
		int i = 0;
		long ans = 0;
		bool negative = false;

		//����ǰ��ո��ж�����
		while (str[i] == ' ') i++;
		if (str[i] == '-')
		{
			negative = true;
			i++;
		}
		else if (str[i] == '+')
			i++;

		//�Էǿպͷ�+-�ŵ���Ч���ֽ��д���
		for (; i < str.size(); i++)
		{
			if (str[i] >= '0' && str[i] <= '9')  //�ж��Ƿ�Ϊ��Ч����
			{
				ans = ans * 10 + (str[i] - '0');  //***�ַ����ת����int
				if (ans > INT_MAX && negative) return INT_MIN;
				if (ans > INT_MAX && !negative) return INT_MAX;
			}
			else        //��������Ч���־��˳�
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
			istringstream is;  //�ַ���ת���ֵĿ⺯�����Զ��ж��Ƿ�Խ�磬���Һ��Ե�һ����0����ǰ�������0�����>INT32_MAX, �򷵻�INT32_MAX�����С��INT_MIN,�򷵻�INT_MIN
			is.str(s1);
			is >> value;
		}

		return value;
	}
};
