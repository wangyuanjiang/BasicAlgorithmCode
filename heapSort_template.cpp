#include<iostream>
#include<vector>
using namespace std;
////////////////////////////��������////////////////////////////////////////////
template <typename T> void Max_Heapify(T data[], int index, int heapsize);

template <typename T> void Build_Max_Heapify(T data[], int heapsize);

template <typename T> void Heap_Sort(T data[], int heapsize);
///////////////////////////////////////////////////////////////////////////

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

template <typename T> void Build_Max_Heapify(T data[], int heapsize)
{
	//���ѹ���
	
	for (int i = heapsize / 2 - 1; i >= 0; i--)  // heapsize �ǽ�������������ڽ���±꣬�����ȫ�������Ľ����5
		                                         // �����һ������������е�С����4����
	{
		Max_Heapify(data, i, heapsize);
		//ֻ��Ҫ���ӽ������Ľ����е���
	}
}


template <typename T> void Heap_Sort(T data[], int heapsize)
{
	// ���������壬����Build_Max_Heapify�� ���鹹��ɴ󶥶ѡ��������֮��data[0]�������ֵ��
	
	Build_Max_Heapify(data, heapsize);

	// Ȼ��data[0]�����һ��Ԫ�ؽ����������¹���󶥶ѣ� ��date�����һ��Ԫ���Ѿ������ѭ������ʱ��Ҫ�ڿ������һ��Ԫ��

	for (int i = heapsize - 1; i > 0; i--)
	{
		swap(data[0], data[i]);

		Max_Heapify(data, 0, i);
	}

}
