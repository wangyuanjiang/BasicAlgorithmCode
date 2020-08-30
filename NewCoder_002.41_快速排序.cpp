#include <iostream>
#include<string>
#include<vector>
#include <cstdlib>
#include <ctime>
using namespace std;

class myclass {

public:
	int partition(vector<int>& data,  int start, int end) 
	{
		if (data.empty() || start < 0 || end >= data.size())
			throw new std::exception("Invalid Parametaters");


		srand((int)time(0));
		int index = rand() % (end - start + 1) + start;  //c++ ������� ���ѡȡ����ֵ��
		swap(data[index], data[end]);					//������ֵ��ĩβԪ�ؽ���

		int small = start - 1;
		for (index = start; index < end; ++index)		//��������
		{
			if (data[index] < data[end])				//�����λ�õ�ֵС������ֵ����++small��Ȼ�󽻻���������ڻ�׼ֱֵ������
			{
				++small;
				if (small != index)
					swap(data[index], data[small]);		//�Ѹ�λ��Ԫ�غ�ǰ���һ����С������ֵ��Ԫ�ؽ�����
			}
		}
		
		++small;						//��֤smallָ���һ����С������ֵ���±�
		swap(data[end], data[small]); //index �����Ѿ���ĩβ,�����Ѹտ�ʼ���λ�õ�Ԫ�غ�data[small]������
		return small;

	}


	void QuickSort(vector<int>& data, int start, int end)
	{
		if (start == end)
			return;
		int index = partition(data, start, end);
		if (index > start)
			QuickSort(data, start, index - 1);
		if (index < end)
			QuickSort(data, index + 1, end);
	}


	///////////////////////////�����/////////////////////////////////////////
	int partition_my(vector<int>& data, int start, int end)
	{
		if (data.empty() || start < 0 || end >= data.size())
			throw new std::exception("Invalid Parametaters");

		srand((int)time(0));
		int index = rand() % (end - start + 1) + start;  //c++ �����
		//swap(data[index], data[end]);  // �����λ��Ԫ�ؽ�����ĩβ

		int small = start - 1;
		for (int i = start; i < end; ++i)
		{
			if (data[i] < data[index])
			{
				++small;
				if (small != i)
					swap(data[i], data[small]);
			}
		}
		++small;
		swap(data[index], data[small]); //�Ѹտ�ʼ���λ�õ�Ԫ�غ�data[small]������
									 //�������ԣ�data[index]�Ѿ��ı��ˣ������ʼ���Ǹ�ֵ��
		return small;

	}

};

////////////////////////////////////////////////////////////////////////////////////////////////

int partition(vector<int>& data, int start, int end)
{
	if (data.empty() || start < 0 || end >= data.size())
		throw new std::exception("Invalid Parametaters");


	srand((int)time(0));
	int index = rand() % (end - start + 1) + start;  //c++ �����
	swap(data[index], data[end]);  // �����λ��Ԫ�ؽ�����ĩβ

	int small = start - 1;
	for (index = start; index < end; ++index)
	{
		if (data[index] < data[end])
		{
			++small;
			if (small != index)
				swap(data[index], data[small]);
		}
	}
	++small;
	swap(data[end], data[small]); //index �����Ѿ���ĩβ,�����Ѹտ�ʼ���λ�õ�Ԫ�غ�data[small]������
	return small;

}


void QuickSort(vector<int>& data, int start, int end)
{
	if (start == end)
		return;
	int index = partition(data, start, end);
	if (index > start)
		QuickSort(data, start, index-1 );
	if (index < end)
		QuickSort(data, index+1 , end);
}

int main_quicksort()
{
	vector<int> nums = { 10, 5, 4, -10, 2, 0, 3, 7, 9,1 };
	for (auto i : nums) {
		cout << i << ' ';
	}
	QuickSort(nums, 0, nums.size()-1);

	cout << endl << "--------�����----------" << endl;;
	for (auto i : nums) {
		cout << i << ' ';
	}

	system("pause");
	return 0;
}