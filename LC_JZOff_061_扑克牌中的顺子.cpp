#include "JZOff.h"

class Solution {	//排序，统计0的个数 cntof0， 计算够成顺子需要0的个数 needof0；
public:
	bool isStraight(vector<int>& numbers) {
		if (numbers.empty())
			return false;

		sort(numbers.begin(), numbers.end());

		int cntof0 = 0, needof0 = 0;
		for (int i = 0; i < numbers.size() - 1; i++)
		{
			if (numbers[i] == 0)
			{
				cntof0++;
				continue;
			}

			if (numbers[i] == numbers[i + 1])
				return false;

			needof0 += numbers[i + 1] - numbers[i] - 1;
			if (cntof0 < needof0)
				return false;
		}

		return true;
	}
};

class Solution {	//不排序
		/*一共只有5个数构成顺子必须不能有非0的重复
		如果最大减最小大于等于5 则必然出现空隙
		除此之外必然所有情况都满足条件*/
public:
	bool isStraight(vector<int>& nums) {
		unordered_map<int, int> cnt;
		int upper = -1;
		int lower = 100;

		for (auto num : nums) {
			cnt[num]++;
			if (num != 0) {
				if (cnt[num] > 1) return false;
				upper = max(upper, num);
				lower = min(lower, num);
			}
		}

		if (cnt[0] >= 4) return true;
		int delta = upper - lower;
		if (delta >= 5) return false;

		return true;
	}
};
