
#include <iostream>

#include<vector>
using  namespace std;

class simple_Select_sort
{
public:

	void Select_Sort(vector<int>& data);
private:
	vector<int> data;
};

void simple_Select_sort::Select_Sort(vector<int>& data) {

	for (int i = 0; i < data.size() - 1; i++)
	{
		int min = i;
		for (int j = i + 1; j < data.size(); j++)
		{
			if (data[j] < data[min])	
				min = j;
		}
		if (min != i)
			swap(data[i], data[min]);
	}


	return;
}