

#include<iostream>
#include<string>
#include<cstdio>
#include<cstring>
using namespace std;
const int maxn = 10;
char p[maxn];
char t[maxn];
bool dp[maxn][maxn];
/*给出两个字符串，分别是模式串P和目标串T，判断模式串和目标串是否匹配，匹配输出 1，不匹配输出 0。
模式串中‘？’可以匹配目标串中的任何字符，模式串中的 ’*’可以匹配目标串中的任何长度的串，
模式串的其它字符必须和目标串的字符匹配。例如P=a?b，T=acb，则P 和 T 匹配。*/

int main_meituanzfcpibei()
{
	string p, t;
	cin >> p >> t;
	int lenp = p.length();
	int lent = t.length();
	dp[0][0] = 1;
	for (int i = 1; i <= lenp; i++)
		dp[i][0] = dp[i - 1][0] && p[i - 1] == '*';
	for (int i = 1; i <= lent; i++)
		for (int j = 1; j <= lenp; j++)
		{
			if (p[j - 1] == t[i - 1] || p[j - 1] == '?')
				dp[j][i] = dp[j - 1][i - 1];
			if (p[j - 1] == '*')
				dp[j][i] = dp[j][i - 1] || dp[j - 1][i];
		}
	if (dp[lenp][lent])
		cout << "1";
	else
	{
		cout << "0";
	}
	system("pause");
	return 0;
}