#include <iostream>
#include<string>
#include<vector>
#include<cstdlib>
#include<ctime>

using namespace std;

class MyClass_QiuckSort
{
public:
	MyClass_QiuckSort();
	~MyClass_QiuckSort();

	int Partition(vector<int>& data, int low, int hight) 
	{
		int tamp = data[low];	//对当前数组中第一个值设为枢轴值，对数组进行划分
		while (low < hight)
		{
			while  (low < hight && data[hight] >= tamp) hight--;
			data[low] = data[hight]; 	//比枢轴值小的移到左边
			while(low < hight && data[low] <= tamp)	low++;
			data[hight] = data[low];  //比枢轴值大的移到右边
		}
		data[low] = tamp;	//将枢轴元素放回最终位置
		return low;		// 返回存放枢轴最终位置
	}

	void QuickSort(vector<int>& data, int low, int hight)
	{
		int index = Partition(data, low, hight);
		if (index > low)
			QuickSort(data, low, index - 1);
		if (index < hight)
			QuickSort(data, index + 1, hight);

	}
private:

};

MyClass_QiuckSort::MyClass_QiuckSort()
{
}

MyClass_QiuckSort::~MyClass_QiuckSort()
{
}