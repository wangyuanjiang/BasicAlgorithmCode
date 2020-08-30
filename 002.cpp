#include<iostream>
#include<string>
#include<stack>
#include<vector>
using namespace std;
int main002() {
	int n;
	string s;
	char flag;
	stack<char> s1;
	cin >>n;
	cin >> s;
	if (!s.size())
		return 0;
	else {
		s1.push(s[0]);
			for (size_t i = 1; i <n; ++i) {
				flag = s1.top();
				if (s1.empty())
					s1.push(s[i]);
				if (flag == s[i])
					s1.push(s[i]);
				if (flag != s[i] && s1.empty() == 0)
					s1.pop();
			}
			return s1.size();
	}

}