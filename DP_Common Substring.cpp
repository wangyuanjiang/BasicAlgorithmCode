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
				if (maxLen[i][j] > bigest) bigest = maxLen[i][j];//Ҫ������ĳ���

			}
			else maxLen[i][j] = 0;//���������������У�������ı���

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
					res = s1.substr(i - bigest, i);//����ж��
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
//˼·����̬�滮�������⣬��һ��start��Ǽ���,ע�⽫�϶��Ӵ����ȳ��ֵ��Ǹ����
//dp[i][j] ��ʾ s1����Ϊi��s2����Ϊj ʱ ������Ӵ��ĳ��ȣ�
void findMaxCommonStr(string s1, string s2)
{
	if (s1.length() > s2.length())
		swap(s1, s2);//s1���ڱ���϶̵��Ӵ�
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
					start = i - maxLen;//��¼������Ӵ�����ʼλ��
				}
			}
		}
	cout << s1.substr(start, maxLen) << endl;
}


////////////////////////////////////////////////////////////////////////////////////////////////////////
//�Ƕ�̬�滮

#include<iostream>
#include<string>
using namespace std;
int mainsubstring()
{
	string a, b;
	while (cin >> a >> b)
	{
		if (a.size() > b.size())
			swap(a, b);//ȷ��ǰ���Ϊ�̴�
		string str_m;//�洢������Ӵ�
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
class solution {		//�����ⷨ
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