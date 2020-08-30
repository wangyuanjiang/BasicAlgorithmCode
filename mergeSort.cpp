#include<iostream>
#include<vector>
using namespace std;

/*�ֵ������ٷ�Ȼ�󰴴�С˳�������������֮���ٿ�����ԭ����*/

////////////////////////////////////////////////////////////////

void mergeSort(vector<int>& data);
void Divide(vector<int>& data, int left, int right);
void mergeTow(vector<int>& data, int left, int mid, int right);

////////////////////////////////////////////////////////////////


void mergeSort(vector<int>& data)	//�鲢����
{
	Divide(data, 0, data.size() - 1);
	return;
}

void Divide(vector<int>& data, int left, int right)		//����
{
	if (left == right)
	return;

	int mid = left + ((right - left) >> 1);	//����1λ���ȼ���/2;
 

	Divide(data, left, mid);	//�ݹ�ֳ����С���֣�ֱ�������ٷ֣�
	Divide(data, mid + 1, right);
	mergeTow(data, left, mid, right);	//	����֮���ٺ�������

	return;
}

void mergeTow(vector<int>& data, int left, int mid, int right)	//�ϲ������ǰ����������鰴˳��ϲ���һ�������飬Ȼ���ٸ��Ƹ�ԭ����
{
	vector<int> temp = vector<int>(right - left + 1, 0);
	int i = 0;
	int p1 = left;
	int p2 = mid + 1;

	// �Ƚ�����������Ԫ�أ��ĸ�С����С��Ԫ������temp
	while (p1 <= mid && p2 <= right)
	{
		temp[i++] = data[p1] < data[p2] ? data[p1++] : data[p2++];

	}

	// �����ѭ���˳�֮�󣬰�ʣ���Ԫ����������temp
	// ��������whileֻ��һ����ִ��
	while (p1 <= mid)
	{
		temp[i++] = data[p1++];
	}

	while (p2 <= right)
		temp[i++] = data[p2++];

	// �����յ�����Ľ�����Ƹ�ԭ����
	for (i = 0; i < temp.size(); i++)
		data[left + i] = temp[i];

	return;
}


