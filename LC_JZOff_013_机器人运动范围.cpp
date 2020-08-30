#include "JZOff.h"

/*������һ��m��n�еķ��񣬴����� [0,0] ������ [m-1,n-1] ��һ�������˴����� [0, 0] �ĸ��ӿ�ʼ�ƶ���
��ÿ�ο��������ҡ��ϡ����ƶ�һ�񣨲����ƶ��������⣩��Ҳ���ܽ�������������������λ֮�ʹ���k�ĸ��ӡ�
���磬��kΪ18ʱ���������ܹ����뷽�� [35, 37] ����Ϊ3+5+3+7=18���������ܽ��뷽�� [35, 38]��
��Ϊ3+5+3+8=19�����ʸû������ܹ�������ٸ����ӣ�
*/
class Solution {
public:
	int movingCount(int m, int n, int k) {
		vector<vector<bool>> used(m, vector<bool>(n, 0));

		int res = backtrack(m, n, k, used, 0, 0);

		return res;

	}
	int backtrack(int m, int n, int k, vector<vector<bool>>& used, int i, int j)
	{
		int res = 0;

		if (i >= 0 && i < m && j < n && j >= 0 && sumofBit(i, j, k) && !used[i][j])
		{
			used[i][j] = true;
			res = 1 + backtrack(m, n, k, used, i - 1, j) 
					+ backtrack(m, n, k, used, i + 1, j)
					+ backtrack(m, n, k, used, i, j - 1) 
					+ backtrack(m, n, k, used, i, j + 1);
		}	//��һ��û��״̬����

		return res;
	}

	bool sumofBit(int i, int j, int k)
	{
		int temp = 0;

		while (i > 0)
		{
			temp += i % 10;
			i = i / 10;

		}

		while (j > 0)
		{
			temp += j % 10;
			j = j / 10;

		}

		if (temp <= k)
			return true;

		return false;
	}

};