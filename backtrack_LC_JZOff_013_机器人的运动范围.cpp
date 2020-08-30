
#include <iostream>
#include <vector>
#include <iomanip> //���Ƹ������ľ���
#include  <string>
#include <algorithm>
//#include <unordered_map>
#include <set>
using namespace std;

/*������һ��m��n�еķ��񣬴����� [0,0] ������ [m-1,n-1] ��һ�������˴����� [0, 0] �ĸ��ӿ�ʼ�ƶ���
��ÿ�ο��������ҡ��ϡ����ƶ�һ�񣨲����ƶ��������⣩��Ҳ���ܽ�������������������λ֮�ʹ���k�ĸ��ӡ�
���磬��kΪ18ʱ���������ܹ����뷽�� [35, 37] ����Ϊ3+5+3+7=18���������ܽ��뷽�� [35, 38]����Ϊ3+5+3+8=19��
���ʸû������ܹ�������ٸ����ӣ�
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