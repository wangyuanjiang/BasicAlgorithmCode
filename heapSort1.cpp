#include<iostream>
#include<vector>
using namespace std;

// 递归方式构建大根堆(len是arr的长度，index是第一个非叶子节点的下标，)
void heapify(vector<int> arr, int len, int index)
{
	int left = 2 * index + 1;  //index的左子节点（完全二叉树的性质）
	int right = 2 * index + 2;

	int max_index = index;

	if (left < len && arr[max_index] < arr[left])
		max_index = left;

	if (right < len && arr[max_index] < arr[right])
		max_index = right;

	if (max_index != index)		//如果根节点发生改变
	{
		swap(arr[max_index], arr[index]);  //交换根节点和比他大的子节点的值
		heapify(arr, len, max_index);		//递归
	}
}

void heapSort(vector<int> arr, int len)
{
	// 构建大根堆（从最后一个非叶子节点向上）
	for (int i = len / 2 - 1; i >= 0; i--)
	{
		heapify(arr, len, i);

	}

	// 调整大根堆
	for (int i = len - 1; i >= 1; i--)
	{
		swap(arr[0], arr[i]);  //把交换最大值交换到末尾
		heapify(arr, i, 0);		// 将未进行排序的部分继续排序
	}
}