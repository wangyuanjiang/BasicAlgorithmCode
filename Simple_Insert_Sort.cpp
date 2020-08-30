
#include <iostream>

#include<vector>
using  namespace std;
class simple_insert_sort
{
public:
	simple_insert_sort();
	~simple_insert_sort();
	void Insert_Sort(vector<int>& data);
private:
	vector<int> data;
};

simple_insert_sort::simple_insert_sort()
{
}

simple_insert_sort::~simple_insert_sort()
{
}

void simple_insert_sort::Insert_Sort(vector<int>& data)
{
	if (data.size() <= 1)
		return;

	for (int i = 1; i < data.size(); i++) {

		if (data[i] < data[i - 1]) {
			int temp = data[i];
			for (int j = i; j >= 0; j--) {
				if (j > 0 && temp < data[j - 1])
					data[j] = data[j - 1];
				else {
					data[j] = temp;
					break;
				}
			}
			/*for (int j = i-1; j >= 0; j--) {
				if ( temp < data[j])
					data[j+1] = data[j];
				else {
					data[j+1] = temp;

				}  
			}*/   // 这样不行

		}
	}
	return;
}

void InsertSort(vector<int> &data) {

	if (data.size() <= 1)
		return;

	for (int i = 1; i < data.size(); i++)
	{
		if (data[i - 1] > data[i])
		{
			int tem = data[i];

			/*for (int j = i-1; j >= 0; j--) {
				
				if (data[j] > tem)

					data[j + 1] = data[j];
				else {
					data[j+1] = tem;
					break;
				}
			}   */  //这样不行
			for (int j = i; j >= 0; j--) {
				if (j > 0 && tem < data[j - 1])	
					data[j] = data[j - 1];		//后移
				else {
					data[j] = tem;
					break;
				}
			}
		}
	}
	return;
}

int main_feb201() {

	vector<int> data;
	int ix;
	while (cin >> ix)
	{
		data.push_back(ix);
		if (cin.get() == '\n')
			break;

	}

	InsertSort(data);

	for (auto x : data)
		cout << x << " ";

	system("pause");
	return 0;
}