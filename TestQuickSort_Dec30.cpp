
#include <iostream>
#include<string>
#include<vector>
#include<cstdlib>
#include<ctime>

using namespace std;

class MyClass
{
public:
	MyClass();
	~MyClass();
	void QuickSort(vector<int>& data,int left, int right);
	int Parition(vector<int>&data, int left, int right);
	int Parition2(vector<int>&data, int left, int right);
private:
	vector<int> data;
		
};

MyClass::MyClass()
{
}

MyClass::~MyClass()
{
}

int MyClass::Parition(vector<int>&data, int left, int right) { // ´íÎó

	int temp = data[left];
	while (left < right) {

		while (left< right && data[right] >= temp) right--;
		swap(data[right], data[left]);
		while (left< right && data[left] <= temp) left++;
		swap(data[right], data[left]);
	}
	data[left] = temp;

	return left;


}

void MyClass::QuickSort(vector<int>& data, int left, int right) {

	int mid = Parition(data, 0, data.size() - 1);

	if (mid > left)
		QuickSort(data, left, mid-1);
	if (mid < right)
		QuickSort(data, mid + 1, right);
}

int MyClass::Parition2(vector<int>&data, int start, int end) {

	if (data.empty() || start < 0 || end >= data.size())
		throw new std::exception("Invalid Parametaters");

	srand((int)time(0));
	int index = rand() % (end - start + 1) + start;  //c++ Ëæ»úÊý
	
	swap(data[index], data[end]);
	int small = start - 1;

	for (int i = start; i < end; i++) {
	
		if (data[i] < data[end])
			small++;
		if (data[i] >= data[end] && small != i)
			swap(data[i], data[small]);
	}

	small++;
	swap(data[end], data[small]);
	return small;


}