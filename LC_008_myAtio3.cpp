#include <iostream>
#include <string>
#include <sstream>
using namespace std;
int myAtoi3(string str) {
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
	//string::size_type  j;
	decltype(s1.size()) j;
	int64_t value1 = 0;
	if (s1.size() > 0)  //
	{
		if (s1[0] == '-')
		{
			 j= 1;
			 while (isdigit(s1[j])) {
				 value1 = value1 * 10 + (s1[j] - '0');// (s1[j] - '0')结果为int型
				 ++j;
				 if (value1 > INT32_MAX+1) {
					 value1 = INT32_MAX + 1;
					 break;
				 }
			 }
			 value = -value1;
		}
		if (s1[0] == '+')
		{
			j = 1;
			while (isdigit(s1[j])) {
				value1 = value1 * 10 + (s1[j] - '0');
				++j;
				if (value1 > INT32_MAX) {
					value1 = INT32_MAX;
					break;
				}
			}
			value = value1;
		}
		if(isdigit(s1[0]))
		{ 
			j = 0;
			while (isdigit(s1[j])) {
				value1 = value1 * 10 + (s1[j] - '0');// (s1[j] - '0')结果为int型
				++j;
				if (value1 > INT32_MAX) {
					value1 = INT32_MAX;
					break;
				}
			}
			value = value1;
		}
	}

	return value;
}


int main_008myAtio()

{

	string str;
	cout << "Please enter sting" << endl;
	getline(cin, str);

	cout << "************" << endl;
	int value1 = myAtoi3(str);
	cout << "***************Reslut of string to int*************** " << endl;
	cout << value1 << endl;

	cout << "INT32_MAX: " << INT32_MAX << endl;
	cout << "INT32_MIN: " << INT32_MIN << endl;
	istringstream is;  //字符串转数字的库函数，自动判断是否越界，如果>INT32_MAX, 则返回INT32_MAX，如果小于INT_MIN,则返回INT_MIN
	string s1 = "-118 12ww";
	int t2;
	is.str(s1);
	is >> t2;
	cout << t2 << endl;
	/*cout << "********************"<<endl;
	sscanf(s1, "%d", &t2);*/
	return 0;
}
