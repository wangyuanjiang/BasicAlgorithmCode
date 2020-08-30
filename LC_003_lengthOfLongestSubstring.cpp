#include <iostream>
#include<string>
#include<set>
#include <vector>
using namespace std;

class solution {
	//��������
	/*������Ҫ�õ�˼·�ǣ���������

		ʲô�ǻ������ڣ�

		��ʵ����һ������, ���������е� abcabcbb������������У����ڣ�Ϊ abc ������ĿҪ�󣬵��ٽ��� a�����б���� abca����ʱ������Ҫ�����ԣ�����Ҫ�ƶ�������У�

		����ƶ���

		����ֻҪ�Ѷ��е���ߵ�Ԫ���Ƴ������ˣ�ֱ��������ĿҪ��

		һֱά�������Ķ��У��ҳ����г�����ĳ���ʱ������⣡

		ʱ�临�Ӷȣ�O(n)O(n)

	*/
	int lengthOfLongestSubstring(std::string s) {  //�������ַ���
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