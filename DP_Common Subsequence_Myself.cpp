
#include<iostream>
#include<string>
#include<algorithm>
#include<vector>

using namespace std;
//-----------------------------------声明---------------------------
int myLCS(string s1, string s2, vector<vector<int>>& flag);
string myGetLCS(string s1, string s2, vector<vector<int>>& flag);

//-----------------------------------定义--------------------------
//dp[i][j] 表示 s1长度为i，s2长度为j 时 最长公共子序列的长度；
//flag[i][j] 表示 移动方向，用于获取公共子子序列；
int myLCS(string s1, string s2, vector<vector<int>>& flag)
{
	vector<vector<int>> dp(s1.size() + 1, vector<int>(s2.size() + 1, 0));

	for (int i = 0; i < s1.size() + 1; i++)
		dp[i][0] = 0;
	for (int i = 0; i < s2.size() + 1; i++)
		dp[0][i] = 0;

	for (int i = 1; i <= s1.size(); i++)
		for (int j = 1; j <= s2.size(); j++)
		{
			if (s1[i - 1] == s2[j - 1]) {
				dp[i][j] = dp[i - 1][j - 1] + 1;
				flag[i][j] = 1;
			}
			else if (dp[i - 1][j] > dp[i][j - 1]) {
				dp[i][j] = dp[i - 1][j];
				flag[i][j] = 2;
			}
			else {
				dp[i][j] = dp[i][j - 1];
				flag[i][j] = 3;
			}
		}
	return dp[s1.size()][s2.size()];
}

string myGetLCS(string s1, string s2, vector<vector<int>>& flag)
{
	string res = "";
	int i = s1.size();
	int j = s2.size();

	while (i > 0 && j > 0) {

		if (flag[i][j] == 1) {
			//	res.append(1, s1[i]);
			res.append(1, s1[i - 1]);
			i--;
			j--;
		}
		else if (flag[i][j] == 2)
			i--;
		else if (flag[i][j] == 3)
			j--;
	}
	//reserve(res.begin(), res.end());
	reverse(res.begin(), res.end());//要反着输出
	//res.reserve();
	return res;

}

int main_dpcomsubsequence_myself() {

	string s1, s2;
	cin >> s1 >> s2;

	vector<vector<int>> flag(s1.size() + 1, vector<int>(s2.size() + 1, 0));

	int maxcomlen = myLCS(s1, s2, flag);
	cout << maxcomlen << endl;

	string res = myGetLCS(s1, s2, flag);
	cout << res;

	system("pause");
	return 0;
}