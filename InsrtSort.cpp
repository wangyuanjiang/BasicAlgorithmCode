#include<vector>
#include<iostream>
using namespace std;

template<class T>
void InsertSort(T* array, int n) {               //array����������,n:����Ԫ������
	int i, j;                                    //ѭ������
	T temp;                                      //�洢������Ԫ��
	for (i = 1; i < n; i++) {

		temp = array[i];      //������Ԫ�ظ�ֵ����ʱ����
		j = i;
		while (j > 0 && temp < array[j - 1]) {   //��δ�ﵽ����ĵ�һ��Ԫ�ػ��ߴ�����Ԫ��С�ڵ�ǰԪ��
			array[j] = array[j - 1];             //�ͽ���Ԫ�غ���
			j--;                                 //�±��һ�������Ƚ�
		}
		array[j] = temp;                         //����λ���Ѿ��ҵ�����������
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