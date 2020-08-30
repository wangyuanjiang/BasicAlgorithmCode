#include<vector>
#include<iostream>
using namespace std;

template<class T>
void InsertSort(T* array, int n) {               //array待排序数组,n:数组元素数量
	int i, j;                                    //循环变量
	T temp;                                      //存储待排序元素
	for (i = 1; i < n; i++) {

		temp = array[i];      //待排序元素赋值给临时变量
		j = i;
		while (j > 0 && temp < array[j - 1]) {   //当未达到数组的第一个元素或者待插入元素小于当前元素
			array[j] = array[j - 1];             //就将该元素后移
			j--;                                 //下标减一，继续比较
		}
		array[j] = temp;                         //插入位置已经找到，立即插入
	}
}

template<class T>
void InsertSort1(vector<T>& data) {//?????????????????????

	for (size_t i = 1; i < data.size(); i++) {

		if (data[i] < data[i - 1])
		{
			T temp = data[i];
			for (size_t j = i; j >= 0; j--) {

				if (j > 0 && data[j] < data[j - 1])
					data[j] = data[j - 1];
				else
				{
					data[j] = temp;
					break;
				}
			}

		}
	}
}