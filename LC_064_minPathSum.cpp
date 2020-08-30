#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
using namespace std;
class Solution {
public:
	int minPathSum(vector<vector<int>>& grid)
	{
		if (grid.size() == 0)
			return 0;
		//if (grid.size() == 1)
			//return grid[0][0];
		vector<vector<int>> minPath(grid);
		int t = 0;
		for (size_t j = 0; j < grid[0].size(); j++) {
			t = grid[0][j] + t;
			minPath[0][j] = t;
		}
		t = 0;
		for (size_t i = 0; i < grid.size(); i++) {
			t = grid[i][0] + t;
			minPath[i][0] = t;
		}
		for (size_t i = 1; i < grid.size(); i++)
			for (size_t j = 1; j < grid[0].size(); j++) {
				/*if (minPath[i - 1][j] > minPath[i][j - 1])
					minPath[i][j] = minPath[i][j - 1] + grid[i][j];
				else
					minPath[i][j] = minPath[i-1][j] + grid[i][j];
				*/
				minPath[i][j] = minPath[i - 1][j] < minPath[i][j - 1] ? minPath[i - 1][j] + grid[i][j] : minPath[i][j - 1] + grid[i][j]; //minPath[i][j]=min(minPath[i-1][j],minPath[i][j-1])+grid[i][j];
			   //问号表达式竟然比if else 快？
			}
		return minPath[grid.size() - 1][grid[0].size() - 1];
	}

	//reference https://blog.csdn.net/weixin_40673608/article/details/86659359
	int minPathSum1(vector<vector<int>>& grid)
	{
		if (grid.size() == 0)
			return 0;
		//if (grid.size() == 1)
			//return grid[0][0];
		//vector<vector<int>> minPath(grid);
		auto minPath = new vector<vector<int>>(grid);
		int t = 0;
		for (size_t j = 0; j < grid[0].size(); j++) {
			t = grid[0][j] + t;
			(*minPath)[0][j] = t;
		}
		t = 0;
		for (size_t i = 0; i < grid.size(); i++) {
			t = grid[i][0] + t;
			(*minPath)[i][0] = t;
		}
		for (size_t i = 1; i < grid.size(); i++)
			for (size_t j = 1; j < grid[0].size(); j++) {
				
				(*minPath)[i][j] = (*minPath)[i - 1][j] < (*minPath)[i][j - 1] ? (*minPath)[i - 1][j] + grid[i][j] : (*minPath)[i][j - 1] + grid[i][j];
			}
		t = (*minPath)[grid.size() - 1][grid[0].size() - 1];
		delete  minPath;
				return t;
	}
};