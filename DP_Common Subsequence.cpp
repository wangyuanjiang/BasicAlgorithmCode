// Dynamic Programming.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
const int MAX_LEN = 1000;
int maxLen[MAX_LEN + 1][MAX_LEN + 1];
int flag[MAX_LEN + 1][MAX_LEN + 1];//1——斜向下走，2——向右标记，3——向下标记
using namespace std;
int LCS(string s1, string s2) {
	for (int i = 0; i <= s1.length(); i++) maxLen[i][0] = 0;
	for (int i = 0; i <= s2.length(); i++) maxLen[0][i] = 0;
	for (int i = 1; i <= s1.length(); i++) {
		for (int j = 1; j <= s2.length(); j++) {
			if (s1[i - 1] == s2[j - 1]) {
				maxLen[i][j] = maxLen[i - 1][j - 1] + 1;
				flag[i][j] = 1;
			}
			else if (maxLen[i - 1][j] > maxLen[i][j - 1]) {
				maxLen[i][j] = maxLen[i - 1][j];
				flag[i][j] = 2;
			}
			else {

				maxLen[i][j] = maxLen[i][j - 1];
				flag[i][j] = 3;
			}
		}
	}
	return maxLen[s1.length()][s2.length()];
}
void getLCS(string s1, string s2) {//逆向找出最长公共子序列
	string res = "";
	int i = s1.length();
	int j = s2.length();
	while (i > 0 && j > 0) {
		if (flag[i][j] == 1) {
			res.append(1, s1[i - 1]); // res.append(n, c) 在 n个c追加到res上
			i--;
			j--;
		}
		else if (flag[i][j] == 2) i--;
		else if (flag[i][j] == 3) j--;
	}
	reverse(res.begin(), res.end());//要反着输出
	cout << res << endl;
}

int mainsubsequence() {
	string s1, s2;
	cin >> s1 >> s2;
	memset(flag, 0, sizeof(flag));
	cout << LCS(s1, s2) << endl;
	getLCS(s1, s2);
	cin.get();
	cin.get();
	return 0;
}
