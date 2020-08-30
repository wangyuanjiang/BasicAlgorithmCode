#include <iostream>
#include<string>
#include<set>
#include <vector>
using namespace std;

class solution {
	//滑动窗口
	/*道题主要用到思路是：滑动窗口

		什么是滑动窗口？

		其实就是一个队列, 比如例题中的 abcabcbb，进入这个队列（窗口）为 abc 满足题目要求，当再进入 a，队列变成了 abca，这时候不满足要求。所以，我们要移动这个队列！

		如何移动？

		我们只要把队列的左边的元素移出就行了，直到满足题目要求！

		一直维持这样的队列，找出队列出现最长的长度时候，求出解！

		时间复杂度：O(n)O(n)

	*/
	int lengthOfLongestSubstring(std::string s) {  //返回子字符串
		int left = 0, right = 0, curlen, maxlen, ans = 0;
		std::set<char> cent;
		std::set<char> res;
		while (left < s.size() && right < s.size()) {

			if (cent.find(s[right]) != cent.end()) {
				cent.erase(s[left]);
				left++;
			}
			else {
				cent.insert(s[right]); 
				right++;
				ans = ans > right - left ? ans : right - left;
				
			}
		}
		return ans;
	}

	string LongestSubstring2(std::string s) {
		int left = 0, right = 0, curlen, maxlen= 0, begin = 0;
		std::set<char> cent;
			string str;
		while (left < s.size() && right < s.size()) {

			if (cent.find(s[right]) != cent.end()) {
				cent.erase(s[left]);
				left++;
			}
			else {
				cent.insert(s[right]);
				right++;
				if (maxlen < right - left) {
					maxlen = right - left;
					begin = left;
				}

			}
		}
		
		str = s.substr(begin, maxlen);
		//cout << str << endl;

		return str;
	}

	string  lengthOfLongestSubstring3(std::string &s);

	
};
	 
string solution::lengthOfLongestSubstring3(string &s) {

	vector <vector<bool>> dp(s.size(), vector<bool>(s.size(), false));
	int max = 1, beg=0;
	for (int i = 0; i < s.size(); i++) {
		set<char> unrepeat;
		unrepeat.insert(s[i]);
		for (int j = i + 1; j < s.size(); j++)
		{
			auto it = unrepeat.insert(s[j]);

			if (it.second && max < j - i + 1) {
				max = j - i + 1;
				beg = i;
			}
			if (!it.second) {
				unrepeat.clear();
				break;
			}
		}
	}
	return s.substr(beg, max);
}