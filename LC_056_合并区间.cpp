
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {	//双指针
public:
	vector<vector<int>> merge(vector<vector<int>>& intervals) {
		if (intervals.size() == 0 || intervals.size() == 1) return intervals;
		// initialize
			int u = 0, v = 0;
		vector<vector<int>> ans;
		// 思路①
			std::sort(intervals.begin(), intervals.end());
		// 思路②
			while (v < intervals.size()) {
				if (intervals[v][0] > intervals[u][1]) {	//不包含，也不相交，压入res
					ans.emplace_back(intervals[u]);
					u = v;
				}
				else if (intervals[v][1] <= intervals[u][1]) {  //包含，直接++v
					++v;
				}
				else {
					intervals[u][1] = intervals[v][1];		//相交，将a[u]扩展
					++v;
				}
			}
		// 思路③
			ans.emplace_back(intervals[u]);
		return ans;
	}
};

class Solution {
public:
	//排序 
	vector<vector<int>> merge(vector<vector<int>>& intervals) {
		vector<vector<int>> res;  //声明res
		if (intervals.empty()) return res;  //判断边界

		sort(intervals.begin(), intervals.end()); //将区间的左边界进行排序
		int index = 0;  //res的遍历索引
		res.push_back(intervals[0]);    //先将intervals的第一个区间放到res里面
		for (int i = 1; i < intervals.size(); i++)  //遍历intervals的其他区间
		{
			if (res[index][1] >= intervals[i][0]) //res从index开始,由于intervals已经排序，如果满足res[index]的右区间 大于 
			{                                    //intervals[i]的左区间，表明这两个区间有交集
				if (res[index][1] < intervals[i][1]) //除此之外,还要判断res[index]的右区间 与 intervals[i]的右区间的关系，
				{                                   //如果res[index]的右区间 小于 intervals[i]的右区间,则取代,反之不变。
					res[index][1] = intervals[i][1];  //例如 [[1,4] ,[2,3]] -> [[1,4]]
				}
			}
			else
			{
				index++;  //如果不满足有联通区域，直接将index++，并将当前的intervals[i] 放到res里面，进行下一时刻的合并
				res.push_back(intervals[i]);
			}
		}
		return res;
	}
};

