
#include <iostream>
#include <vector>
#include <iomanip> //控制浮点数的精度
#include  <string>
#include <algorithm>
//#include <unordered_map>
#include <set>
using namespace std;

/*地上有一个m行n列的方格，从坐标 [0,0] 到坐标 [m-1,n-1] 。一个机器人从坐标 [0, 0] 的格子开始移动，
它每次可以向左、右、上、下移动一格（不能移动到方格外），也不能进入行坐标和列坐标的数位之和大于k的格子。
例如，当k为18时，机器人能够进入方格 [35, 37] ，因为3+5+3+7=18。但它不能进入方格 [35, 38]，因为3+5+3+8=19。
请问该机器人能够到达多少个格子？
*/

class Solution {
public:
	int movingCount(int m, int n, int k) {

		vector<vector<bool> > used(m, vector<bool>(n, false));
		
		
		int res = backtrack(m, n, k, used, 0, 0);

		return res;
	}

	int backtrack(int m, int n, int k, vector<vector<bool> >& used, int row, int col)
	{
		int res = 0;
		
		if (row >=0 && row < m && col >=0 && col< n && !used[row][col] && getSumofBit(row, col, k))
		{
			
			used[row][col] = true;

			res = 1 + backtrack(m, n, k, used, row + 1, col)
				+ backtrack(m, n, k, used, row - 1, col)
				+ backtrack(m, n, k, used, row, col - 1)
				+ backtrack(m, n, k, used, row, col + 1);

		}

		return res;
	}

	bool getSumofBit(int row, int col, int k)
	{
		int res = 0;
		while (row)
		{
			res += row % 10;
			row /= 10;

		}

		while (col)
		{
			res += col % 10;
			col /= 10;
		}

		if (res <= k)
			return true;

		return false;
	}
};