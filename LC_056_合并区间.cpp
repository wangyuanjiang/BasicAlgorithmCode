
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {	//˫ָ��
public:
	vector<vector<int>> merge(vector<vector<int>>& intervals) {
		if (intervals.size() == 0 || intervals.size() == 1) return intervals;
		// initialize
			int u = 0, v = 0;
		vector<vector<int>> ans;
		// ˼·��
			std::sort(intervals.begin(), intervals.end());
		// ˼·��
			while (v < intervals.size()) {
				if (intervals[v][0] > intervals[u][1]) {	//��������Ҳ���ཻ��ѹ��res
					ans.emplace_back(intervals[u]);
					u = v;
				}
				else if (intervals[v][1] <= intervals[u][1]) {  //������ֱ��++v
					++v;
				}
				else {
					intervals[u][1] = intervals[v][1];		//�ཻ����a[u]��չ
					++v;
				}
			}
		// ˼·��
			ans.emplace_back(intervals[u]);
		return ans;
	}
};

class Solution {
public:
	//���� 
	vector<vector<int>> merge(vector<vector<int>>& intervals) {
		vector<vector<int>> res;  //����res
		if (intervals.empty()) return res;  //�жϱ߽�

		sort(intervals.begin(), intervals.end()); //���������߽��������
		int index = 0;  //res�ı�������
		res.push_back(intervals[0]);    //�Ƚ�intervals�ĵ�һ������ŵ�res����
		for (int i = 1; i < intervals.size(); i++)  //����intervals����������
		{
			if (res[index][1] >= intervals[i][0]) //res��index��ʼ,����intervals�Ѿ������������res[index]�������� ���� 
			{                                    //intervals[i]�������䣬���������������н���
				if (res[index][1] < intervals[i][1]) //����֮��,��Ҫ�ж�res[index]�������� �� intervals[i]��������Ĺ�ϵ��
				{                                   //���res[index]�������� С�� intervals[i]��������,��ȡ��,��֮���䡣
					res[index][1] = intervals[i][1];  //���� [[1,4] ,[2,3]] -> [[1,4]]
				}
			}
			else
			{
				index++;  //�������������ͨ����ֱ�ӽ�index++��������ǰ��intervals[i] �ŵ�res���棬������һʱ�̵ĺϲ�
				res.push_back(intervals[i]);
			}
		}
		return res;
	}
};

