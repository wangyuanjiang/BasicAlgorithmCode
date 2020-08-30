

#include <iostream>
#include <vector>
#include <iomanip> //���Ƹ������ľ���
#include  <string>
#include <algorithm>
#include <unordered_map>
#include <set>
using namespace std;

/* ����2020��̨��������7�� �����ɵ�����, �ٶ���N�������� �������N��˾����ÿ��������ƥ��˾��ǰ����Ժ�ѡ˾�����д�֣���ֵĽ��������N*N�ľ���A�� ����Aij ������i˾��jƥ��ķ�ֵ��
�ٶ�ÿ������ֻ���ɸ�һλ˾����˾��ֻ�ܷ��䵽һ�������������յ��ɵ������ʹ��ƥ��Ķ�����˾���ķ�ֵ�ۼ�������󣬲������ж����õ����䡣

�������� :

��һ�а���һ������N��2��N��10��
�ڶ�������N + 1�а���N*N�ľ���

������� :

�����ֵ�ۼӽ����ƥ���б�����������뱣��С�������λ
��ע������ж����ɵ���ʽ�õ��Ľ����ͬ��������Ϊ���С��˾��������С�Ķ��������磺˾��1�õ�1�ŵ���˾��2�õ�2�ŵ����ͱ�˾��1�õ�2�ŵ���˾��2�õ�1�ŵ�Ҫ�ã�
*/

//�ܽ���˵���ǣ� ��һ����ά���飬��ÿ������ѡȡһ��Ԫ����ӣ����Ǹ�Ԫ�ص����������ظ�����͵����ֵ�������ѡ���Ԫ�أ�

class Solution07 {
	double res = -1.0;
	double cur_res = 0;

	void backtrack(vector< vector<double> >& matrix, vector<int>& record, vector<int>& cur_record,
		vector<bool>& used, int index)
	{
		if (index == matrix.size())
		{
			if (cur_res > res)
			{
				res = cur_res;
				record = cur_record;
			}

			return;
		}

		for (int i = 0; i < matrix.size(); i++)
		{
			if (!used[i])
			{
				cur_res += matrix[index][i];	//!!!!!!!!!!!!!!!!
				cur_record.push_back(i);	//��¼�Ͷ���ƥ���˾���� cur_record[0]=i ,��ʾ0�Ŷ���ƥ��i��˾����
				used[i] = true;

				backtrack(matrix, record, cur_record, used, index + 1);

				cur_res -= matrix[index][i];
				cur_record.pop_back();
				used[i] = false;
			}
		
		}
	}

	void fun(int n, vector< vector<double> >& matrix)
	{
		vector<int> record;
		vector<int> cur_record;
		vector<bool> used(n, false);
		
		backtrack(matrix, record, cur_record, used, 0);

		//printf("%.2f", res); // C ���Ƹ�������С��λ��
		cout << fixed << setprecision(2) << res << endl; //C++����double ��С��λ��

		for (int i = 0; i < record.size(); i++)
		{
			cout << i + 1 << " " << record[i] + 1 << endl; // i+1 �Ƕ����ţ� record[i] +1 ��˾���ţ�
		}

		return;
	}
};