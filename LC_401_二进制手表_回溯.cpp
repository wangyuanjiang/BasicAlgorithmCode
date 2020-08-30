#include<iostream>
#include<vector>
#include<algorithm>
#include <set>
#include <string>
#include <math.h>
using namespace std;



class Solution
{
public:
	vector<string> res;
	vector<string> readBinaryWatch(int num)
	{
		vector<int> time(10);
		dfs(0, num, time);
		return res;
	}

	void dfs(int count, int num, vector<int> time)
	{
		if (count >= num)
		{
			int hour = 1 * time[0] + 2 * time[1] + 4 * time[2] + 8 * time[3];
			int min = 1 * time[4] + 2 * time[5] + 4 * time[6] + 8 * time[7] + 16 * time[8] + 32 * time[9];

			if (hour <= 11 && min <= 59)
			{
				char buffer[6];
				sprintf(buffer, "%d:%.2d", hour, min);
				//想在这里判断buffer与res的元素是否重复，无法解决DS匹配问题
				res.push_back(buffer);
			}


			return;
		}
		else
		{
			int max = -1;                    //改为这里操作，让其按序，不重复
			for (int j = 0; j <= 9; ++j)
			{
				if (time[j] == 1)
				{
					max = j;
				}
			}
			for (int pos = 0; pos <= 9; ++pos)
			{
				
				if (pos > max)
				{
					time[pos]++;

					dfs(count + 1, num, time);

					time[pos]--;
				}
				
			}
		}
	}


};

class Solution {	//超时
public:
	set<string> res;
	vector<string> ans;
	vector<string> readBinaryWatch(int num)
	{
		vector<int> time(10, 0);
		vector<bool> used(10, false);
		backtrack(0, num, time, used);

		for (auto it = res.begin(); it != res.end(); it++)
			ans.push_back(*it);

		return ans;
	}

	void backtrack(int cnt, int num, vector<int>& time, vector<bool>& used)
	{
		if (cnt == num)
		{
			int hour = 1 * time[0] + 2 * time[1] + 4 * time[2] + 8 * time[3];
			int mine = 1 * time[4] + 2 * time[5] + 4 * time[6] + 8 * time[7] + 16 * time[8] + 32 * time[9];
			if (hour < 12 && mine < 60) {
				string s = "";
				if (mine >= 10)
					s = to_string(hour) + ":" + to_string(mine);
				else
					s = to_string(hour) + ":" + "0" + to_string(mine);

				// res.push_back(s);
				res.insert(s);
			}
			return;

		}

		else
		{
			/*  int max = -1;
			  for(int j=0; j<=9; j++)
			  {
				  if(time[j] == 1)
				  {
					  max =j;
				  }
			  }*/

			for (int i = 0; i < 10; i++)
			{
				if (!used[i])
				{
					time[i]++;
					used[i] = true;

					backtrack(cnt + 1, num, time, used);

					time[i]--;
					used[i] = false;
				}

			}
		}
	}
};
class Solution {	//超时
public:
	vector<string> readBinaryWatch(int num) {

		set<string> res;
		vector<int> tem;
		int h = 0;
		int m = 0;
		vector<bool> used(10, false);
		backtrack(num, res, tem, used, h, m);
		vector<string> ans;
		for (auto it = res.begin(); it != res.end(); it++)
			ans.push_back(*it);
		return ans;
	}

	void backtrack(int num, set<string> &res, vector<int>& tem, vector<bool>& used, int& h, int& m)

	{
		if (tem.size() == num)
		{
			if (h < 12 && m < 60) {
				string s = "";
				s += to_string(h);
				s += ":";
				if (m < 10)
					s += to_string(0);

				s += to_string(m);

				res.insert(s);

			}
			return;
		}

		for (int i = 0; i < 10; i++)
		{
			if (!used[i])
			{
				tem.push_back(i);
				if (i < 4)
					h += pow(2, i);
				else
					m += pow(2, i - 4);

				used[i] = true;

				backtrack(num, res, tem, used, h, m);

				tem.pop_back();

				if (i < 4)
					h -= pow(2, i);
				else
					m -= pow(2, i - 4);

				used[i] = false;
			}

		}
	}
};

