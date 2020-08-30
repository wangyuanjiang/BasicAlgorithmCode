
#include "JZOff.h"

//��̬�滮 ��״̬��ʾ��dp[i][j]����ʾͶ���� i ö���Ӻ󣬵���֮�� j �ĳ��ִ�����
/*��״̬ת�Ʒ���:
Ҳ�����Ҹ����׶�֮���ת����ϵ��ͬ�����ǻ���ֻ��������һ���׶Σ���������״̬����εõ��ġ�
���һ���׶�Ҳ����Ͷ���� n ö���Ӻ������׶Σ������� dp[n][j] ����ʾ���һ���׶ε���֮�� j ���ֵĴ�����
�������� n ö���ӣ����ĵ�������Ϊ 1 , 2, 3, ... , 6
���Ͷ���� n ö���Ӻ����֮�� j ���ֵĴ�����������Ͷ���� n-1 ö���Ӻ�
��Ӧ����֮�� j-1, j-2, j-3, ... , j-6 ���ֵĴ���֮��ת����

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