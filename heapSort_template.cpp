#include<iostream>
#include<vector>
using namespace std;
////////////////////////////函数声明////////////////////////////////////////////
template <typename T> void Max_Heapify(T data[], int index, int heapsize);

template <typename T> void Build_Max_Heapify(T data[], int heapsize);

template <typename T> void Heap_Sort(T data[], int heapsize);
///////////////////////////////////////////////////////////////////////////

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

template <typename T> void Build_Max_Heapify(T data[], int heapsize)
{
	//建堆过程
	
	for (int i = heapsize / 2 - 1; i >= 0; i--)  // heapsize 是结点数量（区别于结点下标，如该完全二叉树的结点数5
		                                         // 则最后一个结点在数组中的小标是4，）
	{
		Max_Heapify(data, i, heapsize);
		//只需要除子结点以外的结点进行调整
	}
}


template <typename T> void Heap_Sort(T data[], int heapsize)
{
	// 堆排序主体，先用Build_Max_Heapify把 数组构造成大顶堆。构造完成之后data[0]就是最大值，
	
	Build_Max_Heapify(data, heapsize);

	// 然后将data[0]和最后一个元素交换，再重新构造大顶堆， 这date的最后一个元素已经是最大，循环构造时不要在考虑最后一个元素

	for (int i = heapsize - 1; i > 0; i--)
	{
		swap(data[0], data[i]);

		Max_Heapify(data, 0, i);
	}

}
