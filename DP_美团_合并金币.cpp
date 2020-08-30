
#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
using namespace std;

/*�� N �ѽ���ų�һ�ţ��� i ������ C[i] ���ҡ�ÿ�κϲ����Ὣ���ڵ����ѽ�Һϲ�Ϊһ�ѣ�
�ɱ�Ϊ�����ѽ�ҿ���֮�͡�����N-1�κϲ������ս����н�Һϲ�Ϊһ�ѡ����ҳ�����Һϲ�Ϊһ�ѵ���ͳɱ���
���У�1 <= N <= 30��1 <= C[i] <= 100*/


int main_MergeGoldCoin()
{
	int n = 0;
	while (cin >> n)
	{
		vector<int> v(n + 1);
		vector<vector<int>> dp(n + 1, vector<int>(n + 1, INT_MAX));
		vector<vector<int>> sum(n + 1, vector<int>(n + 1, 0));
		for (int i = 1; i <= n; i++)
		{
			cin >> v[i];
		}
		for (int i = 1; i <= n; i++)
		{
			sum[i][i] = v[i];
			dp[i][i] = 0;
		}
		for (int len = 1; len < n; len++)  // ���䳤��
		{
			for (int i = 1; i + len <= n; i++)  //�������
			{
				int j = i + len; //�����յ�
				for (int k = i; k < j; k++)
				{
					sum[i][j] = sum[i][k] + sum[k + 1][j];
					dp[i][j] = min(dp[i][j], dp[i][k] + dp[k + 1][j] + sum[i][j]);
				}
			}
		}
		cout << dp[1][n] << endl;

	}
}