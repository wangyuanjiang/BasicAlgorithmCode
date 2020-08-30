#include <iostream>
#include <vector>
#include <iterator>
using namespace std;


//--------------------声明----------------------------
int min(int x, int y);

vector<int> Merge(vector<int> &data, int begin, int mid, int end);
vector<int> MergeSort(vector<int> data);

void printVec(vector<int> &vec);

//--------------------------------------------------

int min(int x, int y)
{
	return x < y ? x : y;
}

vector<int> Merge(vector<int> &data, int begin, int mid, int end)
{
	int len1 = mid - begin +1;
	int len2 = end - mid;
	//auto it_begin = data.begin();

	//vector<int> left(it_begin, it_begin + len1);//初始化 
	//vector<int> right(it_begin + mid + 1, it_begin+end-1 );
	vector<int> left(len1,0);//初始化 
	vector<int> right(len2,0);

	for (int i = 0; i < len1; i++) {
		left[i] = data[begin + i];
	}
	for (int i = 0; i < len2; i++) {
		right[i] = data[mid + i + 1];
	}


	int i = 0, j = 0, k = begin;
	while (i < len1 && j < len2)
	{
		if (left[i] <= right[j])
			data[k++] = left[i++];
		else
			data[k++] = right[j++];
	}
	//只会执行一个while
	while (i < len1)
		data[k++] = left[i++];

	while (j < len2)
		data[k++] = right[j++];

	return data;
}

vector<int> MergeSort(vector<int> data)
{
	vector<int> res;
	if (data.empty())
	{
		return res;
	}

	/*int size = 1, left, right, mid;
	while (size < data.size())
	{
		left = 0;
		while (left + size < data.size())
		{
			mid = left + size - 1;
			
			right = min(mid + size, data.size() - 1);

			Merge(data, left, mid, right);
			left = right + 1;
			//left += 2 * size;

		}

		size *= 2;


	}*/
	unsigned int i = 1;
	while (i < data.size()) {
		for (unsigned int begin = 0; begin < data.size(); begin += 2 * i) {
			int mid = begin + i - 1;
			int end = min(begin + 2 * i - 1, data.size() - 1);
			res = Merge(data, begin, mid, end);
		}
		i = 2 * i;
	}
	return res;
}

int main_merg()
{
	//vector<int> data = { 1, 4, 6,8, 3,4, 5,1,-10 };
	//int len = sizeof(number) / sizeof(number[0]);
	vector<int>data = {1,3,2,0,10,-1,20,100,4,5,6};
	int len = data.size();
	vector<int> res;
	res = MergeSort(data);
	for (int i = 0; i < len; i++)
		cout <<res[i] << " ";

	system("pause");
	return 0;

}