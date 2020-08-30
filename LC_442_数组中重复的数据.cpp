/*����һ���������� a������1 �� a[i] �� n ��nΪ���鳤�ȣ�, ������ЩԪ�س������ζ�����Ԫ�س���һ�Ρ�
�ҵ����г������ε�Ԫ�ء�
����Բ��õ��κζ���ռ䲢��O(n)ʱ�临�Ӷ��ڽ�����������
*/

/*�������飬Ԫ����Ϊ������Ӧλ�ü�n
�������飬�������Σ����Ӧλ�ô���2n*/
#include <iostream>

#include <vector>
//#include <map>
using namespace std;



class Solution {
public:
	vector<int> findDuplicates(vector<int>& nums) {

		int n = nums.size();
		for (int i = 0; i < nums.size(); i++)
		{
			int index = (nums[i] - 1) % n;
			nums[index] += n;
		}

		vector<int> res;

		for (int i = 0; i < n; i++)
		{
			if (nums[i] > 2 * n)
				res.push_back(i + 1);
		}

		return res;

	}
};