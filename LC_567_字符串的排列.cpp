
#include <iostream>
#include<vector>
#include <algorithm>
#include <string>
using namespace std;

/*��s1�����У���ζ��s1�е��ַ���������һ��ֻ��˳���ϲ�ͬ��
��s1�ĳ���Ϊһ������need��ͳ�Ƹ����ַ��ĸ�����
��s2�У����������ƶ���s1�ȳ��Ĵ���W��ͳ�ƴ���W�е��ַ������Ƚ�need��W��
��need��W���ʱ����ʾ������
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


class Solution {		//��������ʱ
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
		sort(str.begin(), str.end()); //������Ҳ��ͨ���������������һ��
		string temp;
		vector<bool> flag(str.size(), 0);
		Permutation(str, res, temp, flag);
		return res;
	}

	void Permutation(string& str, vector<string>& res, string& temp, vector<bool>flag) {

		if (temp.size() == str.size()) {    //����Ҳ��
			res.push_back(temp);
			return;
		}
		/*if (currentSize == str.size()) {    //����Ҳ��
			res.push_back(temp);
			return;
		}*/

		for (int i = 0; i < str.size(); i++) {	//����ģ��

			if (flag[i] == false) {
				if (i > 0 && str[i] == str[i - 1] && flag[i - 1])// ��֦
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
