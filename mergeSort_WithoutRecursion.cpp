#include <iostream>
#include <vector>
#include <iterator>
using namespace std;

//================声明====================
int min(int x, int y);
vector<int> Merge(vector<int> &data, int begin, int mid, int end);
vector<int> MergeSort(vector<int> data);
void printVec(vector<int> &vec);
//=================定义==================
int min(int x, int y) {
	return (x < y) ? x : y;
}

vector<int> Merge(vector<int> &data, int begin, int mid, int end) {
	int len1 = mid - begin + 1;
	int len2 = end - mid;
	//int left[n1], right[n2];
	vector<int> left(len1, 0);
	vector<int> right(len2, 0);

	for (int i = 0; i < len1; i++) {	//从中间将数组分成两部分
		left[i] = data[begin + i];		//左边部分拷贝给 数组
	}
	for (int i = 0; i < len2; i++) {
		right[i] = data[mid + i + 1];	//右边部分拷贝给右数组
	}

	int i = 0, j = 0, k = begin;
	while (i < len1 && j < len2) {		//将两个子数组安装大小顺序合并成一个数组
		if (left[i] <= right[j]) {
			data[k++] = left[i++];
		}
		else {
			data[k++] = right[j++];
		}
	}

	while (i < len1) {
		data[k++] = left[i++];
	}
	while (j < len2) {
		data[k++] = right[j++];
	}

	return data;
}

vector<int> MergeSort(vector<int> data) {
	vector<int> res;
	if (data.empty()) {
		return res;
	}
	
	int size = 1, left, right, mid;
	while (size < data.size())
	{
		left = 0;
		while (left + size < data.size())
		{
			mid = left + size - 1;
			right = min(mid + size, data.size() - 1);

			res = Merge(data, left, mid, right);

			left = right + 1;
		}

		size *= 2;

	}
	return res;
}

void printVec(vector<int> &vec) {
	if (vec.empty()) {
		return;
	}
	for (vector<int>::iterator it = vec.begin(); it != vec.end(); it++) {
		cout << *it << " ";
	}
	cout << endl;
}

int main_mer1()
{
	//int arr[] = { 12, 11, 13, 5, 6, 7, 100, 5, 5, 5, 55, 5 };
	//vector<int> vec(arr, arr + 6);
	vector<int> vec = { 12, 11, 13, 5, 6, 7, 100, 5, 5, 5, 55, 5, -1, 101};
	vector<int> res;

	cout << "the origonal array:" << endl;
	printVec(vec);

	res = MergeSort(vec);
	cout << "the merge sort array:" << endl;
	printVec(res);

	system("pause");
	return 0;
}
