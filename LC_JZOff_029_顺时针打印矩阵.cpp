
#include "JZOff.h"

class Solution {		// 加入上下左右四个标志位，能够轻松解决；
public:
	vector<int> spiralOrder(vector<vector<int>>& matrix) {

		vector<int> res;
		if (matrix.empty())
			return res;
		int low = 0;
		int hight = matrix.size() - 1;
		int left = 0;
		int right = matrix[0].size() - 1;

		while (low <= hight && left <= right)
		{
			//向右
			for (int i = left; i <= right; i++)
				res.push_back(matrix[low][i]);

			//向下
			for (int i = low + 1; i <= hight; i++)
				res.push_back(matrix[i][right]);

			//向左   有可能出现特殊的情况只有一列，为了避免重复访问, 当只有一列时就不需要向左了
			if (low < hight)
				for (int i = right - 1; i >= left; i--)
					res.push_back(matrix[hight][i]);

			//向上   有可能出现特殊的情况只有一行，为了避免重复访问，当只有一行时就不需要向上了
			if (left < right)
				for (int i = hight - 1; i > low; i--)
					res.push_back(matrix[i][left]);

			low++;
			hight--;
			left++;
			right--;
		}

		return res;

	}

};