
#include <iostream>
#include<vector>
#include <algorithm>
#include <string>
using namespace std;

/*找s1的排列，意味着s1中的字符必须排在一起，只是顺序上不同。
以s1的长度为一个窗口need，统计各个字符的个数。
在s2中，从左向右移动与s1等长的窗口W，统计窗口W中的字符数。比较need与W。
当need与W相等时，表示包含。
*/

class Solution {
public:
	bool checkInclusion(string s1, string s2) {

		if (s2.size() < s1.size())	return false;

		vector<int> need(26, 0);
		vector<int> window(26, 0);
		int right = 0, left = 0;
		for (int i = 0; i < s1.size(); i++)
		{
			need[s1[i] - 'a']++;
			window[s2[right++] - 'a']++;
		}

		if (need == window)		return true;

		while (right < s2.size())
		{
			window[s2[right++] - 'a']++;
			window[s2[left++] - 'a']--;

			if (need == window)		return true;
		}

		return false;
	}
};


class Solution {		//暴力，超时
public:
	bool checkInclusion(string s1, string s2) {

		vector<string> vec = Permutation(s1);

		for (auto ix : vec)
		{
			if (s2.find(ix) != std::string::npos)
				return true;
		}

		return false;


	}

	vector<string> Permutation(string& str) {
		vector<string> res;
		if (str.empty())
			return res;
		sort(str.begin(), str.end()); //不排序也能通过，但是最好排序一下
		string temp;
		vector<bool> flag(str.size(), 0);
		Permutation(str, res, temp, flag);
		return res;
	}

	void Permutation(string& str, vector<string>& res, string& temp, vector<bool>flag) {

		if (temp.size() == str.size()) {    //这样也行
			res.push_back(temp);
			return;
		}
		/*if (currentSize == str.size()) {    //这样也行
			res.push_back(temp);
			return;
		}*/

		for (int i = 0; i < str.size(); i++) {	//回溯模板

			if (flag[i] == false) {
				if (i > 0 && str[i] == str[i - 1] && flag[i - 1])// 剪枝
					continue;
				temp.push_back(str[i]);
				flag[i] = true;
				Permutation(str, res, temp, flag);
				temp.pop_back();
				flag[i] = false;
			}
		}

	}
};
