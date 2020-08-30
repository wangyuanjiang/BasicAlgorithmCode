

#include<iostream>
#include<vector>
#include<algorithm>
#include <set>
#include <string>
#include <math.h>
using namespace std;


class Solution {
public:
	int countArrangement(int N) {

		vector<bool> used(N + 1, 0);
		used[0] = false;
		vector<int> tem;
		tem.push_back(0);
		int res = 0;
		int pos = 1;
		backtrack(N, tem, used, res, pos);
		return res;

	}
	void backtrack(int N, vector<int>& tem, vector<bool>& used, int& res, int pos)
	{
		if (tem.size() == N + 1)
		{
			res++;
			return;
		}

		for (int i = 1; i < N + 1; i++)
		{
			if (!used[i] && help(i, pos))
			{
				tem.push_back(i);
				used[i] = true;


				backtrack(N, tem, used, res, pos + 1);

				tem.pop_back();
				used[i] = false;
			}
		}
	}

	bool help(int x, int pos)
	{
		if (x % pos == 0 || pos % x == 0)
			return true;
		return false;
	}
};