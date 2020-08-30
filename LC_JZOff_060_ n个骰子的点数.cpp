
#include "JZOff.h"

//动态规划 ；状态表示：dp[i][j]，表示投掷完 i 枚骰子后，点数之和 j 的出现次数。
/*找状态转移方程:
也就是找各个阶段之间的转化关系，同样我们还是只需分析最后一个阶段，分析它的状态是如何得到的。
最后一个阶段也就是投掷完 n 枚骰子后的这个阶段，我们用 dp[n][j] 来表示最后一个阶段点数之和 j 出现的次数。
单单看第 n 枚骰子，它的点数可能为 1 , 2, 3, ... , 6
因此投掷完 n 枚骰子后点数之和 j 出现的次数，可以由投掷完 n-1 枚骰子后，
对应点数之和 j-1, j-2, j-3, ... , j-6 出现的次数之和转化过

*/
class Solution {
public:
	vector<double> twoSum(int n) {

		const int g_maxValue = 6;

		vector<vector<int>> dp(n + 1, vector<int>((g_maxValue + 1) * n, 0));

		for (int i = 0; i <= g_maxValue; i++)
			dp[1][i] = 1;

		for (int i = 2; i <= n; i++)
		{
			for (int j = i; j <= g_maxValue * i; j++)
			{
				for (int cur = 1; cur <= g_maxValue; cur++) {
					if (cur >= j)	break;
					dp[i][j] += dp[i - 1][j - cur];
				}

			}

		}
		vector<double> res;
		double all = pow(g_maxValue, n);
		for (int i = n; i <= n * g_maxValue; i++)
		{
			res.push_back(dp[n][i] * 1.0 / all);
		}
		return res;
	}
};