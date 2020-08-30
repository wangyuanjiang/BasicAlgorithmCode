
#include<iostream>
#include<vector>
using namespace std;

class Solution { // 刚才开始是错的，修改后正确
public:
	vector<int> singleNumbers(vector<int>& nums) {
		vector<int> res(2, 0);
		int temp = nums[0];		//没必要， 可以直接令temp = 0； 因为0和任何数异或的结果是该数本身；
		for (int i = 1; i < nums.size(); i++)

			temp ^= nums[i];

		int k = getFirstBitOF1(temp);
		int tem1, tem2;
		bool fag1 = true, fag2 = true;
		for (int i = 0; i < nums.size(); i++) {

			if (BitNIs1(nums[i], k)) {  //没必要， 可以直接令temp = 0； 因为0和任何数异或的结果是该数本身；

				if (fag1) {
					tem1 = nums[i];
					fag1 = false;
					continue;
				}
				tem1 ^= nums[i];

			}

			else
			{
				if (fag2) {
					tem2 = nums[i];
					fag2 = false;
					continue;
				}


				tem2 ^= nums[i];


			}
		}

		res[0] = tem1;
		res[1] = tem2;

		return res;


	}

	int getFirstBitOF1(int temp) {

		int cunt = 0;

		//while (temp & 1 == 0)
		while((temp & 1) == 0)  // 优先级
		{
			cunt++;
			//temp >> 1;  //移位运算也需要赋值
			temp = temp >> 1;
		}

		return cunt;
	}
	bool BitNIs1(int a, int n)
	{
		//a >> n; 
		a = a >> n;

		return (a & 1);

	}
};


class Solution { //correct
public:
	vector<int> singleNumbers(vector<int>& nums) {
		vector<int> res(2, 0);
		int temp = 0;
		for (int i = 0; i < nums.size(); i++)

			temp ^= nums[i];

		int k = getFirstBitOF1(temp);
		int tem1 = 0, tem2 = 0;
		//  bool fag1 =true, fag2 = true;
		for (int i = 0; i < nums.size(); i++) {

			if (BitNIs1(nums[i], k)) {


				tem1 ^= nums[i];

			}

			else
			{

				tem2 ^= nums[i];


			}
		}

		res[0] = tem1;
		res[1] = tem2;

		return res;


	}

	int getFirstBitOF1(int temp) {

		int cunt = 0;

		while ((temp & 1) == 0)
		{
			cunt++;
			temp = (temp >> 1);
		}

		return cunt;
	}
	bool BitNIs1(int a, int n)
	{
		a = (a >> n);

		return (a & 1);

	}
};