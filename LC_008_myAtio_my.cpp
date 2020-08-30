#include <iostream>
#include <string>
using namespace std;
int myAtio(string str){
	if (str == " ") return 0;
	int32_t sign = 1;
	uint32_t sign_couter = 0;
	int64_t res = 0;
	int32_t final = 0;
	decltype(str.length()) i;
	for (i = 0; i < str.length(); ++i) {
		if (str[i] == '-') {
			sign = -1;
			sign_couter++;
		}
		if (str[i] == '+') {
			sign = 1;
			sign_couter++;
		}
		if (sign_couter <= 1) {
			if ('0' <= str[i] && str[i] <= '9') {


				res = res * 10 + (str[i] - '0');
				if (sign == -1 && res-1 > INT32_MAX ) { return INT32_MIN;  }
				if (sign == 1 && res > INT32_MAX) { return INT32_MAX;  }
				if (i + 1 < str.length() && str[i + 1] == ' ') break;
				if (i + 1 < str.length() &&( str[i + 1] == '-'||str[i+1]=='+') ) break; //对于0-123这类输入
			}
			else if (str[i] == '-' || str[i] == '+')
			{
				//if (str[i] == '-') sign = -1;
				if (i + 1 < str.length() && str[i + 1] == ' ') break;
			}
			else if (str[i] == ' ') {}
			else
				break;
		}
	}
	final = res * sign;
	return final;
}
int main() {

	string str;
	cout << "Please enter sting" << endl;
	getline(cin, str);

	cout << "************" << endl;
	int value = myAtio(str);
	cout << value <<endl;
	cout << INT64_MAX << endl;
	cout << INT32_MAX << endl;

	return 0;
}