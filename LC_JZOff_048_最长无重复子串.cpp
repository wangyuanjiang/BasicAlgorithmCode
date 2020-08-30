#include "JZOff.h"

class Solution {
public:
	int lengthOfLongestSubstring(string s) {

		vector<int> dp(s.size(), 0);

		map<char, int> mp;
		queue<char> que;
		
		for (int i = 0; i < s.size();)
		{
			if (mp[s[i]] == 0)
			{
				que.push(s[i]);
				dp[i] = que.size();
				mp[s[i]] ++;
				i++;

			}

			while (mp[s[i]] > 0)
			{
				char tem = que.front();
				que.pop();
				mp[tem]--;
			}
		}
		int max = 0;

		for (int ix : dp)
			max = max < ix ? ix : max;

		return max;
	}
};

class Solution {	//»¬¶¯´°¿Ú
public:
	int lengthOfLongestSubstring(string s) {

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

};