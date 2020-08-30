/*
#include <iostream>

#include <vector>
#include <map>
using namespace std;

class MyClass
{
public:
	MyClass();
	~MyClass();

	static void heapSort(vector<int> arr);
	static void heapInsert(vector<int> arr);
	static void heapify(vector<int> arr, int index, int len);
	static void swap(vector<int> arr, int i, int j)
; private:
	
};

MyClass::MyClass()
{
}

MyClass::~MyClass()
{
}
void MyClass :: heapSort(vector<int> arr)
{
	heapInsert(arr);

	int len = arr.size();
	while (len > 1)
	{
		swap(arr, 0, len - 1);
		len--;
		heapify(arr, 0, len);
	}
}

void MyClass::heapInsert(vector<int> arr)
{

}
*/