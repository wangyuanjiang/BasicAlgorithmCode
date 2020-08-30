#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<map>
#include<unordered_map>
//#include<multimap>
#include<set>

using namespace std;

/*�ⷨ1��
����Ĺؼ���������ж�����string����λ�ʣ���һ�ַ������������������������һ���ģ�������λ�ʡ���һ������˼�����Ǵ��key-val�õ�����ǹ�ϣ�����Ⱥ����Ҫ������
���ܵĽ����Ƕ���string��ɢ�м����ȽϺ�ʱ�����ǱȽϱȽϲ���ʱ��
*/
class Solution { // mself
public:
	vector<vector<string>> groupAnagrams(vector<string>& strs) {

		set<vector<int>>set1;
		multimap<vector<int>, string>mulmap;
		for (auto it = strs.begin(); it != strs.end(); it++) {
			vector<int>vec;
			for (auto it1 = it->begin(); it1 != it->end(); it1++)
			{
				vec.push_back(int(*it1));
			}
			sort(vec.begin(), vec.end());
			mulmap.insert({ vec, *it });
			set1.insert(vec);
		}
		vector<vector<string>> ans;
		for (auto it = set1.begin(); it != set1.end(); it++) {
			vector<string>str;
			for (auto beg = mulmap.lower_bound(*it), end = mulmap.upper_bound(*it); beg != end; ++beg)
				str.push_back(beg->second);

			ans.push_back(str);

		}
		return ans;
	}
};


class Solution {
public:
	vector<vector<string>> groupAnagrams(vector<string>& strs) {
		unordered_map<string, vector<string>> hashmap;
		for (auto s : strs) {
			string temp = s;
			sort(temp.begin(), temp.end());
			hashmap[temp].push_back(s);
		}
		int len = hashmap.size();
		vector<vector<string>> ans(len);
		int index = 0;
		for (auto i : hashmap) {
			ans[index] = i.second;
			++index;
		}
		return ans;
	}
};

//�ⷨ2
class Solution {
public:
	/*�տ�ʼ�ҵ��뷨����ͣ���ÿ��������ͣ�Ȼ������set��multimap ������һ�����Ե���ѧ������n��������ͬ����n������һ����ͬ���൱��һ��������Ҫȷ��n��δ֪��������Ȼ����*/
	/*��ʵ������set��multimap�ǿɵģ�ʣ�µ�����������ͨ������ȷ�����������칹��*/
	vector<vector<string>> groupAnagrams(vector<string>& strs) {
		                                       

		vector<vector<string>> vAns;
		unordered_map<double, vector<string>>hmAll;
		map<char, int> hmNum = {//Ϊÿ��Сд��ĸָ��һ�����������������������ʵ�ÿһ����ĸ���������˻�������˻�һ������Ϊ����λ�ʣ��������n�������ĳ˻���ͬ����ô��n������ֻ��һ�ֽ⣻
			{'a',2},{ 'b',3 },{ 'c',5 },{ 'd',7 },{ 'e',11},{ 'f',13 },{ 'g',17 },{ 'h',19 },{ 'i',23 },{ 'j',29 },{ 'k',31 },
			{ 'l',37 },{ 'm',41 },{ 'n',43 },{ 'o',47 },{ 'p',53 },{ 'q',59 },{ 'r',61 },{ 's',67 },{ 't',71 },{ 'u',73 },{ 'v',79 },
			{ 'w',83 },{ 'x',89 },{ 'y',97 },{ 'z',101 }
		};
		for (int i = 0; i < strs.size(); i++) {
			double sum = 1;
			for (int j = 0; j < strs.at(i).size(); j++) {
				sum *= hmNum[strs.at(i).at(j)];
			}
			hmAll[sum].push_back(strs.at(i));
		}
		for (auto iter = hmAll.begin(); iter != hmAll.end(); iter++) {
			vAns.push_back(iter->second);
		}
		return vAns;
	}
};
class Solution {//copy from above;
public:
	vector<vector<string>> groupAnagrams(vector<string>& strs) {
		vector<vector<string>>vAns;
		unordered_map<int64_t, vector<string>> hmAll;
		map<char, int> hmNum = {//Ϊÿ��Сд��ĸָ��һ�����������������������ʵ�ÿһ����ĸ���������˻�������˻�һ������Ϊ����λ�ʣ��������n�������ĳ˻���ͬ����ô��n������ֻ��һ�ֽ⣻
				{'a',2},{ 'b',3 },{ 'c',5 },{ 'd',7 },{ 'e',11},{ 'f',13 },{ 'g',17 },{ 'h',19 },{ 'i',23 },{ 'j',29 },{ 'k',31 },
				{ 'l',37 },{ 'm',41 },{ 'n',43 },{ 'o',47 },{ 'p',53 },{ 'q',59 },{ 'r',61 },{ 's',67 },{ 't',71 },{ 'u',73 },{ 'v',79 },
				{ 'w',83 },{ 'x',89 },{ 'y',97 },{ 'z',101 }
		};

		for (size_t i = 0; i < strs.size(); i++) {
			int64_t sum = 1;
			for (size_t j = 0; j < strs[i].size(); j++) {
				sum *= hmNum[strs[i][j]];
			}
			hmAll[sum].push_back(strs[i]);
		}
		for (auto it = hmAll.begin(); it != hmAll.end(); it++) {
			//vector<string>tem;
			vAns.push_back(it->second);
		}
		return vAns;
	}


};