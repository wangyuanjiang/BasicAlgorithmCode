/*给定一个整数数组 a，其中1 ≤ a[i] ≤ n （n为数组长度）, 其中有些元素出现两次而其他元素出现一次。
找到所有出现两次的元素。
你可以不用到任何额外空间并在O(n)时间复杂度内解决这个问题吗？
*/

/*遍历数组，元素作为索引对应位置加n
遍历数组，出现两次，则对应位置大于2n*/
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