
#include <iostream>

#include <vector>
#include <map>
using namespace std;

/*统计所有数字中每个位中1出现的总数，那么对于某个位，1出现的次数一定是3的倍数+1或0，
那么对这个数%3得到的结果就是目的数字在该位上的值*/


class Solution {
public:
	int singleNumber(vector<int>& nums) {

		int res = 0;
		for (int i = 0; i < 32; i++) {
			int sum = 0;
			for (int j = 0; j < nums.size(); j++)
			{
				sum += (nums[j] >> i) & 1;
			}
			res ^= (sum % 3) << i;		// 等价于 res += (sum % 3) << i;
		}
		return res;

	}
};