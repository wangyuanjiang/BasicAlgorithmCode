// LeetCode_Project.cpp : ���ļ����� "main" ����������ִ�н��ڴ˴���ʼ��������
//

#include <iostream>
#include <string>
#include <sstream>
using namespace std;
int myAtoi2(string str) {
	int flag;
	int value = 0;
	if ('0' <= str[0] && str[0] <= '9')
		flag = 1;
	else if (str[0] == '-'|| str[0] == '+')
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

				
				if (('0' <= str[i] && str[i] <='9')) {
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
			else if (str[i] == '-'|| str[i] == '+') {
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


int main()

{
	
	string str;
	cout << "Please enter sting" << endl;
	getline(cin, str);

	cout << "************" << endl;
	int value1 = myAtoi2(str);
	cout << "***************Reslut of string to int*************** " << endl;
	cout << value1 << endl;

	cout << "INT32_MAX: " << INT32_MAX << endl;
	cout << "INT32_MIN: " << INT32_MIN << endl;
	istringstream is;  //�ַ���ת���ֵĿ⺯�����Զ��ж��Ƿ�Խ�磬���>INT32_MAX, �򷵻�INT32_MAX�����С��INT_MIN,�򷵻�INT_MIN
	string s1 = "-118 12ww";
	int t2;
	is.str(s1);
	is >> t2;
	cout << t2 << endl;
	/*cout << "********************"<<endl;
	sscanf(s1, "%d", &t2);*/
	return 0;
}

