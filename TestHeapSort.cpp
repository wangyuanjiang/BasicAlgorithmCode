

#include<iostream>
#include<vector>
using namespace std;


template <typename T> void Max_Heapify(T data[], int index, int heapsize)
{
	//以某个节点为根节点的子树进行调整，调整为大顶堆。

	// index 是结点在数组中的下标， heapsize是结点数量
	int left = 2 * index + 1;	//结点下下标index的左子结点
	int right = 2 * index + 2;	//结点下标index 的右子结点

	//int parent = index / 2 - 1;	//结点下标index 的父结点

	int max_index = index;

	if (left < heapsize && data[max_index] < data[left])
		max_index = left;
	if (right < heapsize && data[max_index] < data[right])
		max_index = right;

	if (max_index != index)
	{
		swap(data[max_index], data[index]);  //交换， 保证data[index] 是最大值
		Max_Heapify(data, max_index, heapsize); // 递归构造大顶堆；
	}


}

template <typename T> void buildMaxHeap(vector<T>&data, int heapsize) {

	//for (int i = 0; i <= heapsize / 2 - 1; i++)
		//Max_Heapify(data, heapsize, i);

	for (int i = heapsize / 2 - 1; i >= 0; i--)	//建堆过程
		Max_Heapify(data, i, heapsize);
}

template <typename T> void heapSort(vector<T>& data)
{
	int heapsize = data.size();

	buildMaxHeap(data, heapsize);
	//swap(data[0], data[heapsize - 1]);
	for (int i = heapsize - 1; i >= 0; i--) {
	
		swap(data[0], data[i]);
		Max_Heapify(data, i, 0);
		
	}
}