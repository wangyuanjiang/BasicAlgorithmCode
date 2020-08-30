
#include "JZOff.h"
//全排列： 回溯+减枝
class Solution {
public:
	vector<string> permutation(string s) {

		sort(s.begin(), s.end()); //先排序，为了减枝使用
		vector<string> res;
		vector<bool> visited(s.size(), false);
		string tem;
		backtrack(s, res, tem, visited);

		return res;

	}

	void backtrack(string& s, vector<string>& res, string& tem, vector<bool>& visited)
	{
		if (tem.size() == s.size())
		{
			res.push_back(tem);
			return;
		}

		for (int i = 0; i < s.size(); i++)
		{
			if (!visited[i]) {
				if (i > 0 && s[i - 1] == s[i] && !visited[i - 1]) //减枝，s[i - 1] == s[i] 而且s[i-1]没被用过！
					continue;									//其实上一行的if语句的条件中将!visited[i]改成 visitied[i]也行，只不过这样改，在leetcode上会慢20ms左右

				tem += s[i];
				visited[i] = true;
				backtrack(s, res, tem, visited);

				tem.pop_back();
				visited[i] = false;

			}
		}
	}
};