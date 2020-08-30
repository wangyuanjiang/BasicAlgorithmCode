#include<iostream>
#include<vector>
using namespace std;

// �ݹ鷽ʽ���������(len��arr�ĳ��ȣ�index�ǵ�һ����Ҷ�ӽڵ���±꣬)
void heapify(vector<int> arr, int len, int index)
{
	int left = 2 * index + 1;  //index�����ӽڵ㣨��ȫ�����������ʣ�
	int right = 2 * index + 2;

	int max_index = index;

	if (left < len && arr[max_index] < arr[left])
		max_index = left;

	if (right < len && arr[max_index] < arr[right])
		max_index = right;

	if (max_index != index)		//������ڵ㷢���ı�
	{
		swap(arr[max_index], arr[index]);  //�������ڵ�ͱ�������ӽڵ��ֵ
		heapify(arr, len, max_index);		//�ݹ�
	}
}

void heapSort(vector<int> arr, int len)
{
	// ��������ѣ������һ����Ҷ�ӽڵ����ϣ�
	for (int i = len / 2 - 1; i >= 0; i--)
	{
		heapify(arr, len, i);

	}

	// ���������
	for (int i = len - 1; i >= 1; i--)
	{
		swap(arr[0], arr[i]);  //�ѽ������ֵ������ĩβ
		heapify(arr, i, 0);		// ��δ��������Ĳ��ּ�������
	}
}