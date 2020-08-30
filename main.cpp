#include <iostream>
#include<string>
#include<vector>
#include <cstdlib>
#include <ctime>

//#include "NewCoder_002.41_¿ìËÙÅÅĞò.cpp"
using namespace std;
void Insert_Sort(vector<int>& data)
{
	if (data.size() <= 1)
		return;

	for (int i = 1; i < data.size(); i++) {

		if (data[i] < data[i - 1]) {
			int temp = data[i];
			for (int j = i ; j >= 0; j--) {
				if (j>0 && temp < data[j-1 ] )
					data[j ] = data[j-1];
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
			}*/
		
		}
	}
	return;
}

int main_feb20()
{
	vector<int> nums = { 1, 5, 4, -10, 2, 0, 3};
	for (auto i : nums) {
		cout << i << ' ';
	}
	//QuickSort(nums, 0, nums.size()-1);
	cout << endl;
	Insert_Sort(nums);
	for (auto i : nums) {
		cout << i << ' ';
	}

	system("pause");
	return 0;
}