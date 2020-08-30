

#include<iostream>
#include<vector>
using namespace std;


template <typename T> void Max_Heapify(T data[], int index, int heapsize)
{
	//��ĳ���ڵ�Ϊ���ڵ���������е���������Ϊ�󶥶ѡ�

	// index �ǽ���������е��±꣬ heapsize�ǽ������
	int left = 2 * index + 1;	//������±�index�����ӽ��
	int right = 2 * index + 2;	//����±�index �����ӽ��

	//int parent = index / 2 - 1;	//����±�index �ĸ����

	int max_index = index;

	if (left < heapsize && data[max_index] < data[left])
		max_index = left;
	if (right < heapsize && data[max_index] < data[right])
		max_index = right;

	if (max_index != index)
	{
		swap(data[max_index], data[index]);  //������ ��֤data[index] �����ֵ
		Max_Heapify(data, max_index, heapsize); // �ݹ鹹��󶥶ѣ�
	}


}

template <typename T> void buildMaxHeap(vector<T>&data, int heapsize) {

	//for (int i = 0; i <= heapsize / 2 - 1; i++)
		//Max_Heapify(data, heapsize, i);

	for (int i = heapsize / 2 - 1; i >= 0; i--)	//���ѹ���
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