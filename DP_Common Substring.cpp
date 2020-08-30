#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
using namespace std;
const int MAX_LEN = 1000;
int maxLen[MAX_LEN + 1][MAX_LEN + 1];
int bigest = 0;

int conLCS(string s1, string s2) {

	for (int i = 0; i <= s1.length(); i++) maxLen[i][0] = 0;
	for (int i = 0; i <= s2.length(); i++) maxLen[0][i] = 0;
	for (int i = 1; i <= s1.length(); i++) {
		for (int j = 1; j <= s2.length(); j++) {
			if (s1[i - 1] == s2[j - 1]) {
				maxLen[i][j] = maxLen[i - 1][j - 1] + 1;
				if (maxLen[i][j] > bigest) bigest = maxLen[i][j];//要保存最长的长度

			}
			else maxLen[i][j] = 0;//相对于最长公共子序列，就这里改变了

		}
	}
	return bigest;
}
void getLCS(string s1, string s2) {
	string res = "";
	for (int i = 1; i <= s1.length(); i++) {
		for (int j = 1; j <= s2.length(); j++) {
			if (maxLen[i][j] == bigest) {
				if (i - bigest + 1 >= 0) {
					res = s1.substr(i - bigest, i);//输出有多个
					cout << res << endl;
				}
			}
		}
	}
}

int mainsubstring1() {
	string s1, s2;
	cin >> s1 >> s2;

	cout << conLCS(s1, s2) << endl;
	getLCS(s1, s2);
	cin.get();
	cin.get();
	return 0;
}

/////////////////////////////////////////////////////////////////////////////
//思路：动态规划经典问题，加一个start标记即可,注意将较短子串最先出现的那个输出
//dp[i][j] 表示 s1长度为i，s2长度为j 时 最长公共子串的长度；
void findMaxCommonStr(string s1, string s2)
{
	if (s1.length() > s2.length())
		swap(s1, s2);//s1用于保存较短的子串
	int len1 = s1.length(), len2 = s2.length();
	int maxLen = 0, start = 0;
	vector<vector<int> >dp(len1 + 1, vector<int>(len2 + 1, 0));
	for (int i = 1; i <= len1; ++i)
		for (int j = 1; j <= len2; ++j)
		{
			if (s1[i - 1] == s2[j - 1])
			{
				dp[i][j] = dp[i - 1][j - 1] + 1;
				if (dp[i][j] > maxLen)
				{
					maxLen = dp[i][j];
					start = i - maxLen;//记录最长公共子串的起始位置
				}
			}
		}
	cout << s1.substr(start, maxLen) << endl;
}


////////////////////////////////////////////////////////////////////////////////////////////////////////
//非动态规划

#include<iostream>
#include<string>
using namespace std;
int mainsubstring()
{
	string a, b;
	while (cin >> a >> b)
	{
		if (a.size() > b.size())
			swap(a, b);//确保前面个为短串
		string str_m;//存储最长公共子串
		for (int i = 0; i < a.size(); i++)
		{
			for (int j = i; j < a.size(); j++)
			{
				string temp = a.substr(i, j - i + 1);
				if (int(b.find(temp)) < 0)
					break;
				else if (str_m.size() < temp.size())
					str_m = temp;
			}
		}
		cout << str_m << endl;
	}
	return 0;
}
class solution {		//暴力解法
public: int getLCS(string s1, string s2) {
		if (s1 == "" || s2 == "") {
			return 0;
		}

		int l1 = s1.length();
		int l2 = s2.length();
		int res = 0;
		for (int i = 0; i < l1; i++) {
			for (int j = 0; j < l2; j++) {
				int m = i;
				int k = j;
				int len = 0;
				while (m < l1 && k < l2 && s1[m] == s2[k]) {
					len++;
					m++;
					k++;
				}
				res =max(res, len);
			}
		}
		return res;
	}

};

class solution {

	string  findMaxCommonStr(string s1, string s2) {
	
		if (s1.size() > s2.size())
			swap(s1, s2);

		int len1 = s1.size();
		int len2 = s2.size();

		vector<vector<int>> dp (len1 + 1, vector<int>(len2 + 1 , 0));

		int start = 0, maxLen = 0;

		for (int i = 1; i <= len1; i++) {
		
			for (int j = 1; j <= len2; j++)
			{
				if (s1[i - 1] == s2[j - 1])
					dp[i][j] = dp[i - 1][i - 1] + 1;
				if (maxLen < dp[i][j]) {
				
					maxLen = dp[i][j];
					start = i - maxLen;

				}
			}
		}

		string res = s1.substr(start, maxLen);

		return res;
	}
};