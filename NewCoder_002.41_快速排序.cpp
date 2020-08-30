#include <iostream>
#include<string>
#include<vector>
#include <cstdlib>
#include <ctime>
using namespace std;

class myclass {

public:
	int partition(vector<int>& data,  int start, int end) 
	{
		if (data.empty() || start < 0 || end >= data.size())
			throw new std::exception("Invalid Parametaters");


		srand((int)time(0));
		int index = rand() % (end - start + 1) + start;  //c++ 随机数， 随机选取轴枢值，
		swap(data[index], data[end]);					//将轴枢值和末尾元素交换

		int small = start - 1;
		for (index = start; index < end; ++index)		//遍历数组
		{
			if (data[index] < data[end])				//如果该位置的值小于轴枢值，则++small，然后交换，如果大于基准值直接跳过
			{
				++small;
				if (small != index)
					swap(data[index], data[small]);		//把该位置元素和前面第一个不小于轴枢值的元素交换；
			}
		}
		
		++small;						//保证small指向第一个不小于轴枢值的下标
		swap(data[end], data[small]); //index 现在已经是末尾,即，把刚开始随机位置的元素和data[small]交换；
		return small;

	}


	void QuickSort(vector<int>& data, int start, int end)
	{
		if (start == end)
			return;
		int index = partition(data, start, end);
		if (index > start)
			QuickSort(data, start, index - 1);
		if (index < end)
			QuickSort(data, index + 1, end);
	}


	///////////////////////////错误的/////////////////////////////////////////
	int partition_my(vector<int>& data, int start, int end)
	{
		if (data.empty() || start < 0 || end >= data.size())
			throw new std::exception("Invalid Parametaters");

		srand((int)time(0));
		int index = rand() % (end - start + 1) + start;  //c++ 随机数
		//swap(data[index], data[end]);  // 把随机位置元素交换到末尾

		int small = start - 1;
		for (int i = start; i < end; ++i)
		{
			if (data[i] < data[index])
			{
				++small;
				if (small != i)
					swap(data[i], data[small]);
			}
		}
		++small;
		swap(data[index], data[small]); //把刚开始随机位置的元素和data[small]交换；
									 //这样不对，data[index]已经改变了，不是最开始的那个值了
		return small;

	}

};

////////////////////////////////////////////////////////////////////////////////////////////////

int partition(vector<int>& data, int start, int end)
{
	if (data.empty() || start < 0 || end >= data.size())
		throw new std::exception("Invalid Parametaters");


	srand((int)time(0));
	int index = rand() % (end - start + 1) + start;  //c++ 随机数
	swap(data[index], data[end]);  // 把随机位置元素交换到末尾

	int small = start - 1;
	for (index = start; index < end; ++index)
	{
		if (data[index] < data[end])
		{
			++small;
			if (small != index)
				swap(data[index], data[small]);
		}
	}
	++small;
	swap(data[end], data[small]); //index 现在已经是末尾,即，把刚开始随机位置的元素和data[small]交换；
	return small;

}


void QuickSort(vector<int>& data, int start, int end)
{
	if (start == end)
		return;
	int index = partition(data, start, end);
	if (index > start)
		QuickSort(data, start, index-1 );
	if (index < end)
		QuickSort(data, index+1 , end);
}

int main_quicksort()
{
	vector<int> nums = { 10, 5, 4, -10, 2, 0, 3, 7, 9,1 };
	for (auto i : nums) {
		cout << i << ' ';
	}
	QuickSort(nums, 0, nums.size()-1);

	cout << endl << "--------排序后----------" << endl;;
	for (auto i : nums) {
		cout << i << ' ';
	}

	system("pause");
	return 0;
}