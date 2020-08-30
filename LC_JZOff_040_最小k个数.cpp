
#include "JZOff.h"

class Solution {	//解法1 维护一个长度为k的优先队列；优先队列使用降序；
public:
	vector<int> getLeastNumbers(vector<int>& arr, int k) {

		if (arr.empty() || k == 0)    return {};
		if (k >= arr.size()) return arr;

		priority_queue <int, vector<int>, less<int> > que;

		for (int i = 0; i < k; i++) {
			que.push(arr[i]);
		}

		for (int i = k; i < arr.size(); i++)
		{
			if (arr[i] < que.top())
			{
				que.pop();
				que.push(arr[i]);
			}
		}

		vector<int> res(k, 0);

		for (int i = 0; i < k; i++)
		{
			res[i] = que.top();
			que.pop();
		}

		return  res;
	}
};

class Solution {	//解法2 堆排序；
public:
	vector<int> getLeastNumbers(vector<int>& arr, int k) {

		if (arr.empty() || k == 0)    return {};
		if (k >= arr.size()) return arr;

		vector<int> res(k, 0);

		int heapsize = arr.size();

		heapSort(arr,heapsize, k, res);
			
		return res;
	}

	void minHeapfy(vector<int>& arr, int idx, int heapsize)
	{
		int left = 2 * idx + 1;
		int right = 2 * idx + 2;
		int minidx = idx;

		if(left < heapsize && arr[left] < arr[minidx])	  minidx = left;
		if (right < heapsize && arr[right] < arr[minidx])  minidx = right;

		if (idx != minidx)
		{
			swap(arr[idx], arr[minidx]);
			minHeapfy(arr, minidx, heapsize);
		}

	}
		 
	void bulidMinHeap(vector<int>& arr, int heapsize)  
	{
		for (int i = heapsize / 2 - 1; i >= 0; i--)
		{
			minHeapfy(arr, i, heapsize);
		}
	}

	void heapSort(vector<int>& arr, int heapsize,  int k, vector<int>& res)
	{
		bulidMinHeap(arr, heapsize);
		int j =0;
		for (int i = heapsize - 1; i >= 0; i--)
		{
			if (j == k) break;

			res[j++] = arr[0];
			swap(arr[0], arr[i]);
			minHeapfy(arr, 0, i);
		}
	}

};

