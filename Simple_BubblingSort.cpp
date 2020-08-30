
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
		bool flag = false;  //本趟是否交换的标志
		for (int j = data.size() - 1; j > i; j--)	//从后往前依次比较
		{
			if (data[j - 1] > data[j]) {	//如果前面的比后面的大就交换
				swap(data[j - 1], data[j]);
				flag = true;		//发生交换的标志
			}
		}
		if (!flag)	//如果这一趟没有发生交换，说明已经有序；
			return;
	}
}