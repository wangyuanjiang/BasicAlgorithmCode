
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
	vector<vector<int>> threeSum(vector<int>& nums) {
		vector<vector<int>> res;
		vector<int> res1 = { 0,0,0 };
		sort(nums);
		int flag;
		for (auto it = nums.begin(); it != nums.end(); ++it)
			for (auto it1 = it + 1; it1 != nums.end(); ++it1)
				for (auto it2 = it1 + 1; it2 != nums.end(); ++it2)
					if (*it + *it1 + *it2 == 0) {
						//res1.push_back(*it);
						//res1.push_back(*it1);
						//res1.push_back(*it2);
						flag = 1;
						res1[0] = *it;
						res1[1] = *it1;
						res1[2] = *it2;
						for (decltype(res.size()) i = 0; i < res.size(); ++i)
							if (res[i] == res1) {
								flag = 0;
								break;
							}
						if (flag == 1)
							res.push_back(res1);
					}
		return res;
	}
	vector<int> sort(vector<int>& nums) {
		int tar;
		for (auto it = nums.begin(); it != nums.end(); ++it)
			for (auto it1 = it + 1; it1 != nums.end(); ++it1)
				if (*it > *it1) {
					tar = *it1;
					*it1 = *it;
					*it = tar;
				}
		return nums;
	}
};

class Solution {//��ô����ֻ�̶�һ������i����j��k�仯����ǰֵС��targetʱ��������j���ӣ�����k��С��������������:
public:
	/**
	 * @param numbers : Give an array numbers of n integer
	 * @return : Find all unique triplets in the array
	 *           which gives the sum of zero.
	 *           each triplet in non-descending order
	 */
	vector<vector<int> > threeSum(vector<int> &A) {
		// write your code here
		vector<vector<int> > vs;
		int target = 0;
		sort(A.begin(), A.end());    // sort A in ascending order
		for (int i = 0; i < A.size(); ++i) {
			if (i > 0 && A[i - 1] == A[i]) continue;       // skip duplication
			for (int j = i + 1, k = A.size() - 1; j < k;) {
				if (j > i + 1 && A[j - 1] == A[j]) {
					++j;
					continue;       // skip duplication
				}
				if (k < A.size() - 1 && A[k] == A[k + 1]) {
					--k;
					continue;       // skip duplication
				}
				int sum = A[i] + A[j] + A[k];
				if (sum > target) --k;
				else if (sum < target) ++j;
				else {               // find a triplet
					vector<int> v(3, A[i]);
					v[1] = A[j++];
					v[2] = A[k--];
					vs.push_back(v);
				}
			}
		}
		return vs;
	}
};
/*ע��ȥ���ظ��Ľ������һ��������������Ԫ��<a,b,c>��������ظ�����Ԫ����֮��ͬ����˵��a,b,c��������һ��Ԫ�ص�ֵ�������г����������Ρ�
����a��ֵ2���������г��ֶ�Σ������Ȼ�������ģ������Ѿ����򣩣���˿���ʹ�����ϵķ���ȥ���ظ�����Ԫ�顣
�÷���ʱ�临�Ӷ�O(nlogn)+O(n^2)���ռ临�Ӷ�ΪO(1)��*/