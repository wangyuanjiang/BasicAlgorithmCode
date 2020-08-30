#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
using namespace std;
//////////////////////////////////////////////////////////
class Solution {
public:
	string longestPalindrome(string s) {
		if ((s.length() == 0) || (s.length() == 1))return s;
		int len = s.length();
		//创建二维数组
		vector<vector<bool>> flag(len, vector<bool>(len));// vector<int> vec(len)   vec包含len个元素，这些元素进行了值初始化；vector<int> vec(len,t) vec包含len个初始化为t的元素
		int maxLen = 0;
		string result;
		for (int j = 0; j < len; ++j) {
			flag[j][j] = true;
			int i = 0;
			for (i = 0; i < j; ++i) {
				if ((i + 1 <= j - 1) && flag[i + 1][j - 1] && (s[i] == s[j])) {
					flag[i][j] = true;
				}
				else if ((i == j - 1) && (s[i] == s[j])) {
					flag[i][j] = true;
				}
				else {
					flag[i][j] = false;
				}
				if (flag[i][j] && (maxLen < (j - i + 1))) {
					maxLen = (j - i) + 1;
					result = s.substr(i, j - i + 1);
				}
			}
			if (flag[i][j] && (maxLen < (j - i + 1))) {		//有必要，是为了防止出现字符串有多个字符但是只有最长回文子串只有一个字符
				maxLen = (j - i) + 1;
				result = s.substr(i, j - i + 1);
			}
		}
		return result;
	}
};
////////////
class Solution {
public:
	int len;
	string longestPalindrome(string s) {
		//string s1=reverse(s.begin(), s.end());
		int len = s.size();
		string s1;
		s1 = s;
		reverse(s.begin(), s.end());
		// LCS(s,s1);
		int bigest;
		vector<vector<int> > maxLen(len + 1, vector<int>(len + 1));
		vector<vector<int> >flag(len + 1, vector<int>(len + 1));

		for (int i = 0; i <= s.size(); ++i) maxLen[i][0] = 0;
		for (int i = 0; i <= s1.size(); ++i) maxLen[0][i] = 0;
		for (int i = 0; i <= s.size(); ++i) {
			for (int j = 0; j <= s.size(); ++j) {
				if (s[i] == s[j]) {
					maxLen[i][j] = maxLen[i - 1][j - 1] + 1;
					flag[i][j] = 1;
				}
				if (s[i - 1] == s1[j - 1]) {
					maxLen[i][j] = maxLen[i - 1][j - 1] + 1;
					if (maxLen[i][j] > bigest) bigest = maxLen[i][j];//要保存最长的长度

				}
				else maxLen[i][j] = 0;
			}
		}

		string res = "";
		//size_t i=s.size(),j=s1.size();
		for (int i = 1; i <= s.length(); i++) {
			for (int j = 1; j <= s1.length(); j++) {
				if (maxLen[i][j] == bigest) {
					if (i - bigest + 1 >= 0) {
						res = s1.substr(i - bigest, i);//输出有多个
						//cout << res << endl;
					}
				}
			}
		}
		return res;
	}

	/* vector<vector<int> > maxLen(len+1,vector<int>(len+1));

		int LCS(string s,string s1){
			for(int i=0;i<=s.size();++i) maxLen[i][0]=0;
			for(int i=0;i<=s1.size();++i) maxLen[0][i]=0;
			for(int i=0;i<=s.size();++i){
				for(int j=0;j<=s.szie();++j){
					if(s[i]==s[j]){
						maxLen[i][j]=maxLen[i-1][j-1]+1;
						flag[i][j]=1;
					}
					else if(maLen[i-1][j]>maxLen[i][j-1]){
						maxLen[i][j]==maLen[i-1][j];
						flag[i][j]=0;
					}
					else if(maLen[i-1][j]<maxLen[i][j-1]){
						maxLen[i][j]==maLen[i][j-1];
						flag[i][j]=0;
					}
				}
			}
				return maxLen[s.length()][s1.length()];
		}*/


};

class Solution {
public:
	string longestPalindrome(string s) {
		if ((s.length() == 0) || (s.length() == 1))return s;
		int len = s.length();
		//创建二维数组
		vector<vector<int>> maxLen(len + 1, vector<int>(len + 1));
		int bigest = 0;
		string s1;
		s1 = s;
		string res1 = "";
		string  res;
		reverse(s.begin(), s.end());
		for (int i = 0; i <= s1.length(); i++) maxLen[i][0] = 0;
		for (int i = 0; i <= s.length(); i++) maxLen[0][i] = 0;
		for (int i = 1; i <= s1.length(); i++) {
			for (int j = 1; j <= s.length(); j++) {
				if (s1[i - 1] == s[j - 1]) {
					maxLen[i][j] = maxLen[i - 1][j - 1] + 1;
					if (maxLen[i][j] > bigest) bigest = maxLen[i][j];//要保存最长的长度

				}
				else maxLen[i][j] = 0;//相对于最长公共子序列，就这里改变了

			}
		}

		for (int i = 1; i <= s1.length(); i++) {
			for (int j = 1; j <= s.length(); j++) {
				if (maxLen[i][j] == bigest) {
					if (i - bigest + 1 >= 0) {
						res1 = s1.substr(i - bigest, bigest);//输出有多个
						//cout << res << endl;
						 //return res1;

						res.append(res1);
						res1 = res.substr(0, bigest);
					}
				}
			}
		}
		return res1;
	}
};

//暴力解法java
class Solution {
	public String longestPalindrome(String s) {
		if (s.isEmpty()) {
			return s;
		}
		String res = s.substring(0, 1);
		for (int i = 0; i < s.length(); i++) {
			for (int j = i + 1; j <= s.length(); j++) {
				String k = s.substring(i, j);
				String rk = new StringBuffer(k).reverse().toString();
				if (k.equals(rk) && k.length() > res.length()) {
					res = k;
				}
			}

		}
		return res;
	}
};