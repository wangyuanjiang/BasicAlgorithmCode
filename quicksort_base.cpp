#include <iostream>
#include<string>
#include<vector>
#include<cstdlib>
#include<ctime>

using namespace std;

class MyClass_QiuckSort
{
public:
	MyClass_QiuckSort();
	~MyClass_QiuckSort();

	int Partition(vector<int>& data, int low, int hight) 
	{
		int tamp = data[low];	//�Ե�ǰ�����е�һ��ֵ��Ϊ����ֵ����������л���
		while (low < hight)
		{
			while  (low < hight && data[hight] >= tamp) hight--;
			data[low] = data[hight]; 	//������ֵС���Ƶ����
			while(low < hight && data[low] <= tamp)	low++;
			data[hight] = data[low];  //������ֵ����Ƶ��ұ�
		}
		data[low] = tamp;	//������Ԫ�طŻ�����λ��
		return low;		// ���ش����������λ��
	}

	void QuickSort(vector<int>& data, int low, int hight)
	{
		int index = Partition(data, low, hight);
		if (index > low)
			QuickSort(data, low, index - 1);
		if (index < hight)
			QuickSort(data, index + 1, hight);

	}
private:

};

MyClass_QiuckSort::MyClass_QiuckSort()
{
}

MyClass_QiuckSort::~MyClass_QiuckSort()
{
}