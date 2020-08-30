#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

class Solution {
public:
	int myAtoi(string str)
	{
		if (str == "") return 0;  // str.length()==0 �ȼ��� str==""������������дΪif(str=="" || str.length()==0) 
		long long final, res = 0;
		int len = str.length();
		int sign = 1;
		int sign_count = 0;
		for (int i = 0; i < len; i++)
		{
			char ch = str[i];
			if (ch == '-' || ch == '+') sign_count++;
			if (sign_count <= 1)
			{
				if (ch <= '9' && ch >= '0')
				{
					res = res * 10 + ch - '0';
					if (res > INT_MAX && sign == 1) return INT_MAX;   // ������������INT_MAX��INT_MINʱ���輰ʱ�˳�������ȼ������ٷ��أ�final���Ϊ1(�洢Խ��)
					if (res < INT_MIN && sign == -1) return INT_MIN;
					if (i + 1 < len && str[i + 1] == ' ') break;
				}
				else if (ch == '-' || ch == '+')
				{
					if (ch == '-') sign = -1;
					if (i + 1 < len && str[i + 1] == ' ') break;
				}
				else if (ch == ' ');  // ��ͷ�Ŀո���Ե�
				else break;  // ���벻�Ϸ����˳�ѭ��				
			}
			else return 0;
		}
		if (res >= INT_MIN && res <= INT_MAX) final = res * sign;
		else if (sign == 1) final = INT_MAX;
		else if (sign == -1) final = INT_MIN;  // ���Խ�������߽磬������Ӧ��ֵ 
		return final; // -2147483648[(signed int)0x80000000] ~ 2147483647(0x7FFFFFFF)
	}

	
		int StrToInt(string str)
		{
			if (str == "") return 0;
			long long res = 0;
			int len = str.length();
			int isPositive = 1;

			for (int i = 0; i < len; i++)
			{
				char ch = str[i];
				if (ch <= '9' && ch >= '0')  res = res * 10 + ch - '0';
				else if (ch == '-') isPositive = -1;
				else if (ch == '+');  // ��������������ɨ
				else return 0;
			}
			return res * isPositive;
		}
	};



// ����Ϊ����
int main008c()
{
	string str0; //	str0.size() == 0; // ����İ�䣺��д�ɲ�д���ַ���Ĭ�ϳ�ʼ��Ϊ�մ� 
	string str1 = "1ab3";  // Ӧ����1
	string str2 = "-18446744073709551617";
	string str3 = "- +899999 ";
	string str4 = "    010"; // Ӧ����10
	string str5 = "   +0 123";
	string str6 = "13  456"; // 123
	string str7 = "   - 321";

	Solution sol;
	cout << sol.myAtoi(str0) << endl;
	cout << sol.myAtoi(str1) << endl;
	cout << sol.myAtoi(str2) << endl;
	cout << sol.myAtoi(str3) << endl;
	cout << sol.myAtoi(str4) << endl;
	cout << sol.myAtoi(str5) << endl;
	cout << sol.myAtoi(str6) << endl;
	cout << sol.myAtoi(str7) << endl;
	cout << "************" << endl;
	cout << sol.StrToInt(str0) << endl;
	cout << sol.StrToInt(str1) << endl;
	cout << sol.StrToInt(str2) << endl;
	cout << sol.StrToInt(str3) << endl;
	cout << sol.StrToInt(str4) << endl;
	cout << sol.StrToInt(str5) << endl;
	cout << sol.StrToInt(str6) << endl;
	cout << sol.StrToInt(str7) << endl;
	return 0;
}
