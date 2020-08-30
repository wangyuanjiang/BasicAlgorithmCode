
#include "JZOff.h"
//ȫ���У� ����+��֦
class Solution {
public:
	vector<string> permutation(string s) {

		sort(s.begin(), s.end()); //������Ϊ�˼�֦ʹ��
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
				if (i > 0 && s[i - 1] == s[i] && !visited[i - 1]) //��֦��s[i - 1] == s[i] ����s[i-1]û���ù���
					continue;									//��ʵ��һ�е�if���������н�!visited[i]�ĳ� visitied[i]Ҳ�У�ֻ���������ģ���leetcode�ϻ���20ms����

				tem += s[i];
				visited[i] = true;
				backtrack(s, res, tem, visited);

				tem.pop_back();
				visited[i] = false;

			}
		}
	}
};