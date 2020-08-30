#include<iostream>
#include<vector>
using namespace std;

/*分到不能再分然后按大小顺序合起来，合完之后再拷贝给原数组*/

////////////////////////////////////////////////////////////////

void mergeSort(vector<int>& data);
void Divide(vector<int>& data, int left, int right);
void mergeTow(vector<int>& data, int left, int mid, int right);

////////////////////////////////////////////////////////////////


void mergeSort(vector<int>& data)	//归并排序
{
	Divide(data, 0, data.size() - 1);
	return;
}

void Divide(vector<int>& data, int left, int right)		//划分
{
	if (left == right)
	return;

	int mid = left + ((right - left) >> 1);	//右移1位，等价于/2;
 

	Divide(data, left, mid);	//递归分成许多小部分，直到不能再分；
	Divide(data, mid + 1, right);
	mergeTow(data, left, mid, right);	//	分完之后再合起来；

	return;
}

void mergeTow(vector<int>& data, int left, int mid, int right)	//合并，就是把两个子数组按顺序合并成一个大数组，然后再复制给原数组
{
	vector<int> temp = vector<int>(right - left + 1, 0);
	int i = 0;
	int p1 = left;
	int p2 = mid + 1;

	// 比较左右两部分元素，哪个小，把小的元素填入temp
	while (p1 <= mid && p2 <= right)
	{
		temp[i++] = data[p1] < data[p2] ? data[p1++] : data[p2++];

	}

	// 上面的循环退出之后，把剩余的元素依次填入temp
	// 以下两个while只有一个会执行
	while (p1 <= mid)
	{
		temp[i++] = data[p1++];
	}

	while (p2 <= right)
		temp[i++] = data[p2++];

	// 把最终的排序的结果复制给原数组
	for (i = 0; i < temp.size(); i++)
		data[left + i] = temp[i];

	return;
}


