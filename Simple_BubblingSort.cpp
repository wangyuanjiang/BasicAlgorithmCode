
#include <iostream>

#include<vector>
using  namespace std;

class simple_Bubbling_sort
{
public:
	
	void Bubbling_Sort(vector<int>& data);
private:
	vector<int> data;
};

void simple_Bubbling_sort::Bubbling_Sort(vector<int>& data) {

	for (int i = 0; i < data.size(); i++)
	{
		bool flag = false;  //�����Ƿ񽻻��ı�־
		for (int j = data.size() - 1; j > i; j--)	//�Ӻ���ǰ���αȽ�
		{
			if (data[j - 1] > data[j]) {	//���ǰ��ıȺ���Ĵ�ͽ���
				swap(data[j - 1], data[j]);
				flag = true;		//���������ı�־
			}
		}
		if (!flag)	//�����һ��û�з���������˵���Ѿ�����
			return;
	}
}