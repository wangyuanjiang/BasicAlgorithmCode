

#include<iostream>
#include<string>
#include<cstdio>
#include<cstring>
using namespace std;
const int maxn = 10;
char p[maxn];
char t[maxn];
bool dp[maxn][maxn];
/*���������ַ������ֱ���ģʽ��P��Ŀ�괮T���ж�ģʽ����Ŀ�괮�Ƿ�ƥ�䣬ƥ����� 1����ƥ����� 0��
ģʽ���С���������ƥ��Ŀ�괮�е��κ��ַ���ģʽ���е� ��*������ƥ��Ŀ�괮�е��κγ��ȵĴ���
ģʽ���������ַ������Ŀ�괮���ַ�ƥ�䡣����P=a?b��T=acb����P �� T ƥ�䡣*/

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