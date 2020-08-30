// LeetCode_Project.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <string>
#include <vector>
#include <sstream>
using namespace std;
/*int Judge(string str) {
	//if (('a'<str[0]&&str[0]<'z')|| ('A' < str[0] && str[0] < 'Z'))
		//return 0;
		if (('0' < str[0] && str[0] < '9') || str[0] == '-')
			return 1;
		if (str[0] == ' ')
			return -1;
	else 
		return 0;
}*/
int myAtoi(string str) {
	int flag;
	int value = 0;
	if ('0' < str[0] && str[0] < '9')
		flag = 1;
	else if (str[0] == '-')
		flag = 2;
	else if (str[0] == ' ')
		flag = -1;
	else
		flag = 0;
	size_t i = 0;
	std::string s1;
	if (flag == 1)
		while (1) {
			s1.push_back(str[i]);
		   i++;
		  // if (!(('0' < str[i] && str[i] < '9') || str[i] == '-'))//if not is number and -
		   if (!('0' < str[i] && str[i] < '9')) {
			   cout << s1 << endl;
			   break;
		   }
		}
	
	if (flag == 2) {
		if (('0' < str[1] && str[1] < '9')) {
			s1.push_back(str[0]);
			i = 1;
			while (1) {

				// if (!(('0' < str[i] && str[i] < '9') || str[i] == '-'))//if not is number and -
				if (('0' < str[i] && str[i] < '9')) {
					s1.push_back(str[i]);
					i++;
				}
				if (!('0' < str[i] && str[i] < '9')) {
					cout << s1 << endl;
					break;
				}
			}
		}
		else
			//cout << 0 << endl;
			value = 0;
	}
	if(flag==-1)
		while (1) {
			if (str[i] ==' ')
				i++;
			else if (str[i] == '-') {
				if ('0' < str[i + 1] && str[i + 1] < '9') {
					s1.push_back(str[i]);
					i++;
				}
				else {
					//cout << 0 << endl;
					value = 0;
					break;
				}
			}
			else if (('0' < str[i] && str[i] < '9') ) {
				s1.push_back(str[i]);
				i++;
				if (!('0' < str[i] && str[i] < '9')) {
					cout << s1 << endl;
					break;
				}
			}
			
			else {
				//cout << 0 << endl;
				value = 0;
				break;
			}
		}
	if (flag == 0)
		//cout << 0 << endl;
		value = 0;
	if (s1.size() > 0) {
		size_t j, k, len = s1.size();
		
		vector<int>p;
		if (s1[0] != '-') {
			for (j = 0; j < len; j++) {
				p.push_back(1);
				for (k = 0; k < len - j - 1; k++)
					p[j] = p[j] * 10;
			}
			for (j = 0; j < s1.size(); j++)
				value = value + (int(s1[j]) - 48)*p[j];
		}
		else{
			p.push_back(0);
			for (j = 1; j < len; j++) {
				p.push_back(1);
				for (k = 0; k < len - j - 1; k++)
					p[j] = p[j] * 10;
			}
			for (j = 0; j < s1.size(); j++)
				value = value + (int(s1[j]) - 48)*p[j];
			value = -value;
		}
	}
	if(value > INT32_MAX)//or INT_MAX or INT32_MAX
		value = (numeric_limits<int>::max)();
	if(value < INT32_MIN)
		value = (numeric_limits<int>::min)();
	return value;
}


int main0()
{
	/*std::string  str = "2";
	std::string  str1 = "b";
	cout << "***************" << endl;
    std::cout << "Hello World!\n"; 
	cout << int(str[0]) << endl;
	std::cout << ((str[0] > str1[0]) ? str[0] : str1[0]);
	*/

	/*string st1 = "0123456789";
	for(size_t i=0;i<st1.size();i++) 
	cout << int(st1[i] ) << endl;*/
	string str;
	cout << "Please enter sting" << endl;
	getline(cin, str);
	
	cout << "************" << endl;
	int value1 = myAtoi(str);
	cout << "***************Reslut of string to int*************** " << endl;
	cout << value1 << endl;
	//cout << (numeric_limits<int>::min)() << endl;
	//cout << (numeric_limits<int>::max)() << endl;
	cout << INT32_MAX << endl;
	string s3, s4;
	s3 = "100000";
	s4 = "23";
	if (s4 > s3)
		cout << 1 << endl;
	else
		cout << 0 << endl;

	return 0;
}

// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门提示: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件
