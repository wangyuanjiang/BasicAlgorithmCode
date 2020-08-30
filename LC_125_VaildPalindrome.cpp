#include<iostream>
#include<string>
using namespace std;
class Solution {
public:
	bool isPalindrome(string s) {
		size_t i, j;
		string s1;
		if (s.size() == 0 || s.size() == 1)
			return 1;
		else {
			for (i = 0; i < s.size(); ++i) {
				if ((s[i] >= 'a'&&s[i] <= 'z') || (s[i] >= 'A'&&s[i] <= 'Z') || (s[i] >= '0'&&s[i] <= '9'))
					s1.push_back(s[i]);
			}
			if (s1.size() == 0 || s1.size() == 1)
				return 1;
			for (i = 0, j = s1.size() - 1; i < j; ++i, --j) {
				if ((s1[i] != s1[j]) && tolower(s1[i]) != s1[j] && toupper(s1[i]) != s1[j])
					return 0;
			}

		}
		return 1;
	}
};
class Solution {
public:
	bool isPalindrome(string s) {
		size_t i, j;
		string s1;
		if (s.size() == 0 || s.size() == 1)
			return 1;
		else {
			
			for (i = 0, j = s1.size() - 1; i < j; ++i, --j) {
				if (!isdigit(s[i]) && !isalpha(s[i]))
				{
					++i;
				}
				else if (!isdigit(s[j]) && !isalpha(s[j]))
				{
					--j;
				}

				else
					if((s[i] != s[j]) && tolower(s1[i]) != s[j] && toupper(s[i]) != s[j])
					return 0;
			}

		}
		return 1;
	}
};

class Solution {//myself
public:
	bool isPalindrome(string s) {
		size_t i, j;

		if (s.size() == 0 || s.size() == 1)
			return 1;

		else {
			i = 0;
			j = s.size() - 1;
			while (i < j) {
				while (!isdigit(s[i]) && !isalpha(s[i]))
				{
					++i;
					if (i == s.size() - 1)
						break;
				}
				while (!isdigit(s[j]) && !isalpha(s[j]))
				{
					--j;
					if (j == 0)// 如果不判断i，j是否越界的话，会出错
						break;
				}
				if (i >= j) return 1;
				if ((isdigit(s[i]) || isalpha(s[i])) && (isdigit(s[j]) || isalpha(s[j]))) {

					if ((s[i] != s[j]) && tolower(s[i]) != s[j] && toupper(s[i]) != s[j])
						return 0;
					++i;
					--j;
				}

			}

		}
		return 1;
	}
};
class Solution { //others
public:
	bool isPalindrome(string s) {
		int i = 0, j = s.length() - 1;
		while (i < j) {

			while (!isdigit(s[i]) && !isalpha(s[i]) && i < s.length()) {
				i++;
				if (i == s.length() - 1)
					break;
			}
			while (!isdigit(s[j]) && !isalpha(s[j])) {
				j--;
				if (j == 0)// 如果不判断i，j是否越界的话，会出错
					break;
			}
			if (i >= j) return 1;//i=j 说明只有一个有效字符，i>j ，说明没有有效字符
			if (isalpha(s[i])) s[i] = tolower(s[i]);
			if (isalpha(s[j])) s[j] = tolower(s[j]);
			if (s[i] != s[j]) { return 0; }
			i++, j--;

		}
		return 1;
	}
};
