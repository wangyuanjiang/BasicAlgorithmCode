
#include "JZOff.h"

class Solution {		// �������������ĸ���־λ���ܹ����ɽ����
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
			//����
			for (int i = left; i <= right; i++)
				res.push_back(matrix[low][i]);

			//����
			for (int i = low + 1; i <= hight; i++)
				res.push_back(matrix[i][right]);

			//����   �п��ܳ�����������ֻ��һ�У�Ϊ�˱����ظ�����, ��ֻ��һ��ʱ�Ͳ���Ҫ������
			if (low < hight)
				for (int i = right - 1; i >= left; i--)
					res.push_back(matrix[hight][i]);

			//����   �п��ܳ�����������ֻ��һ�У�Ϊ�˱����ظ����ʣ���ֻ��һ��ʱ�Ͳ���Ҫ������
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