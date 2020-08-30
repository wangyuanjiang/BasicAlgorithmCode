

#include <iostream>
#include <vector>
#include <iomanip> //控制浮点数的精度
#include  <string>
#include <algorithm>
#include <unordered_map>
#include <set>
using namespace std;

/* 美团2020后台开发，第7题 ：打车派单场景, 假定有N个订单， 待分配给N个司机。每个订单在匹配司机前，会对候选司机进行打分，打分的结果保存在N*N的矩阵A， 其中Aij 代表订单i司机j匹配的分值。
假定每个订单只能派给一位司机，司机只能分配到一个订单。求最终的派单结果，使得匹配的订单和司机的分值累加起来最大，并且所有订单得到分配。

输入描述 :

第一行包含一个整数N，2≤N≤10。
第二行至第N + 1行包含N*N的矩阵。

输出描述 :

输出分值累加结果和匹配列表，结果四舍五入保留小数点后两位
（注意如果有多组派单方式得到的结果相同，则有限为编号小的司机分配编号小的订单，比如：司机1得到1号单，司机2得到2号单，就比司机1得到2号单，司机2得到1号单要好）
*/

//总结来说就是， 给一个二维数组，从每行里面选取一个元素相加，但是该元素的列数不能重复，求和的最大值并输出所选择的元素，

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
				cur_record.push_back(i);	//记录和订单匹配的司机， cur_record[0]=i ,表示0号订单匹配i号司机；
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

		//printf("%.2f", res); // C 控制浮点数的小数位数
		cout << fixed << setprecision(2) << res << endl; //C++控制double 的小数位数

		for (int i = 0; i < record.size(); i++)
		{
			cout << i + 1 << " " << record[i] + 1 << endl; // i+1 是订单号， record[i] +1 是司机号；
		}

		return;
	}
};