#include<iostream>
#include<string>
#include<algorithm>
#include<vector>

using namespace std;
/*����Ҫ��ȷ��һ�㣺���ִ��������ӽṹ�����⣬һ������ʹ�ö�̬�滮��

���˴��������ת��Ϊ���ȷ�������ӽṹ���Լ�������������ӽṹ���Ƶ���ǰ�����Ž⡣

����һ�����󣬾���Ԫ��Ϊ��Ԫ�� {row, line, area}.

row Ϊ��ǰλ�ôӸõ������ߣ�Ԫ�� '1' �ĳ��ȡ���Ϊ '0' �򵽴�߽� ����ֹ��
line Ϊ��ǰλ�ôӸõ������ߣ�Ԫ�� '1' �ĳ��ȣ���Ϊ '0' �򵽴�߽� ����ֹ��
area Ϊ��ǰλ���ܹ���ľ�����������ֵ��
�����������ȶ��ڵ�һ��/��һ���ϵ�Ԫ�ؽ��ж�̬�滮����Ԫ��ֵΪ 0, ����Ԫ��Ϊ {0,0,0}, ��Ԫ��Ϊ 1, 
�� �� ��Ԫ��Ϊ{ dp[i][j-1][0] + 1, 1, dp[i][j-1][2] + 1},  //������
   �� �ϵ���Ԫ��Ϊ{1, dp[i - 1][j][1] + 1, dp[i - 1][j][2] + 1}. // ������
�����±� i!=0, j != 0 ��Ԫ�أ�dp[i][j][0]��������1�ĸ����� = dp[i][j-1][0] + 1,  dp[i][j][1]��������1�ĸ����� = dp[i - 1][j][1] + 1.
��ؼ���Ϊ�� dp[i][j][2]��������ֵ���֣�
*/
class Solution {
public:
	// dp(i, j, 3)Ϊ��Ԫ�飨����������1�ĸ���������������1�ĸ�������Χ����������
	int maximalRectangle(vector<vector<char>>& matrix) {
		int result = 0;
		if (matrix.empty()) { return result; }
		int m = matrix.size();
		int n = matrix[0].size();
		vector<vector<vector<int>>> dp(m, vector<vector<int>>(n, { 0, 0, 0 }));
		for (int i = 0; i < m; i++) {
			for (int j = 0; j < n; j++) {
				if (matrix[i][j] == '1') {
					if (i == 0 && j == 0) {  // ���Ͻǵ�ֵ
						dp[i][j] = { 1, 1, 1 };
					}
					else if (i == 0) {  // ��һ��
						dp[i][j] = { dp[i][j - 1][0] + 1, 1, dp[i][j - 1][2] + 1 };
					}
					else if (j == 0) {  // ��һ��
						dp[i][j] = { 1, dp[i - 1][j][1] + 1, dp[i - 1][j][2] + 1 };
					}
					else {
						dp[i][j][0] = dp[i][j - 1][0] + 1;  // ��������1�ĸ���
						dp[i][j][1] = dp[i - 1][j][1] + 1;  // ��������1�ĸ���
						// �������
						int col_min = dp[i][j][0];  // ��ǰλ������1�ĸ���
						int row = dp[i][j][1];  // ��ǰλ������1�ĸ���
						
						for (int k = 0; k < row; k++) {		//�����
							col_min = min(col_min, dp[i - k][j][0]);  // ������С��1����
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
					else if (i == 0)	//��һ�У�
					{
						dp[i][j][0] = dp[i][j - 1][0] + 1;
						dp[i][j][1] = 1;
						dp[i][j][2] = dp[i][j - 1][2] + 1;
					}

					else if (j == 0)	//��һ��
					{
						dp[i][j][0] = 1;
						dp[i][j][1] = dp[i-1][j][1] + 1;
						dp[i][j][2] = dp[i - 1][j][2] + 1;
					}

					else 
					{
						dp[i][j][0] = dp[i][j - 1][0] + 1;  // ��������1�ĸ���
						dp[i][j][1] = dp[i - 1][j][1] + 1;  // ��������1�ĸ���
						// �������
						int col_min = dp[i][j][0];  // ��ǰλ������1�ĸ���
						int row = dp[i][j][1];  // ��ǰλ������1�ĸ���

						for (int k = 0; k < row; k++) {		//�����
							col_min = min(col_min, dp[i - k][j][0]);  // ������С��1����
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