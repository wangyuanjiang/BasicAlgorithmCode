#include<iostream>
#include<string>
#include<algorithm>
#include<vector>

using namespace std;
/*首先要明确的一点：这种存在最优子结构的问题，一定可以使用动态规划。

有了大方向，问题就转化为如何确定最优子结构，以及如何利用最优子结构来推导当前的最优解。

设置一个矩阵，矩阵元素为三元组 {row, line, area}.

row 为当前位置从该点向左走，元素 '1' 的长度。若为 '0' 或到达边界 则终止。
line 为当前位置从该点向上走，元素 '1' 的长度，若为 '0' 或到达边界 则终止。
area 为当前位置能构造的矩阵面积的最大值。
遍历矩阵，首先对于第一行/第一列上的元素进行动态规划，若元素值为 0, 则三元组为 {0,0,0}, 若元素为 1, 
则 行 三元组为{ dp[i][j-1][0] + 1, 1, dp[i][j-1][2] + 1},  //往左数
   列 上的三元组为{1, dp[i - 1][j][1] + 1, dp[i - 1][j][2] + 1}. // 往上数
对于下标 i!=0, j != 0 的元素，dp[i][j][0]（往左数1的个数） = dp[i][j-1][0] + 1,  dp[i][j][1]（往上数1的个数） = dp[i - 1][j][1] + 1.
最关键的为求 dp[i][j][2]（面积最大值部分）
*/
class Solution {
public:
	// dp(i, j, 3)为三元组（向左走连续1的个数，向上走连续1的个数，包围的最大面积）
	int maximalRectangle(vector<vector<char>>& matrix) {
		int result = 0;
		if (matrix.empty()) { return result; }
		int m = matrix.size();
		int n = matrix[0].size();
		vector<vector<vector<int>>> dp(m, vector<vector<int>>(n, { 0, 0, 0 }));
		for (int i = 0; i < m; i++) {
			for (int j = 0; j < n; j++) {
				if (matrix[i][j] == '1') {
					if (i == 0 && j == 0) {  // 左上角的值
						dp[i][j] = { 1, 1, 1 };
					}
					else if (i == 0) {  // 第一行
						dp[i][j] = { dp[i][j - 1][0] + 1, 1, dp[i][j - 1][2] + 1 };
					}
					else if (j == 0) {  // 第一列
						dp[i][j] = { 1, dp[i - 1][j][1] + 1, dp[i - 1][j][2] + 1 };
					}
					else {
						dp[i][j][0] = dp[i][j - 1][0] + 1;  // 向左连续1的个数
						dp[i][j][1] = dp[i - 1][j][1] + 1;  // 向上连续1的个数
						// 计算面积
						int col_min = dp[i][j][0];  // 当前位置向左1的个数
						int row = dp[i][j][1];  // 当前位置向上1的个数
						
						for (int k = 0; k < row; k++) {		//求面积
							col_min = min(col_min, dp[i - k][j][0]);  // 向左最小的1个数
							dp[i][j][2] = max(dp[i][j][2], col_min * (k + 1));
						}
					}
					result = max(result, dp[i][j][2]);
				}
			}
		}
		return result;
	}
};

class Solution
{
public:

	int maximalRectangle(vector<vector<char>>& matrix) {

		int res = 0;
		if (matrix.empty()) return 0;
		int m = matrix.size();
		int n = matrix[0].size();
		vector<vector<vector< int > > > dp(matrix.size(), vector<vector<int>>(matrix[0].size(), { 0,0,0 }));

		for (int i = 0; i < m; i++)
		{
			for (int j = 0; j < n; j++)
			{
				if (matrix[i][j] == '1')
				{
					if (i == 0 && j == 0) //dp[0][0];
						dp[i][j] = { 1,1,1 };
					else if (i == 0)	//第一行，
					{
						dp[i][j][0] = dp[i][j - 1][0] + 1;
						dp[i][j][1] = 1;
						dp[i][j][2] = dp[i][j - 1][2] + 1;
					}

					else if (j == 0)	//第一列
					{
						dp[i][j][0] = 1;
						dp[i][j][1] = dp[i-1][j][1] + 1;
						dp[i][j][2] = dp[i - 1][j][2] + 1;
					}

					else 
					{
						dp[i][j][0] = dp[i][j - 1][0] + 1;  // 向左连续1的个数
						dp[i][j][1] = dp[i - 1][j][1] + 1;  // 向上连续1的个数
						// 计算面积
						int col_min = dp[i][j][0];  // 当前位置向左1的个数
						int row = dp[i][j][1];  // 当前位置向上1的个数

						for (int k = 0; k < row; k++) {		//求面积
							col_min = min(col_min, dp[i - k][j][0]);  // 向左最小的1个数
							dp[i][j][2] = max(dp[i][j][2], col_min * (k + 1));
						}

					}
					res = max(res, dp[i][j][2]);
				}
			}
		}

		return res;
	}

};