
#include "JZOff.h"

/*给定一个数字，我们按照如下规则把它翻译为字符串：0 翻译成 “a” ，1 翻译成 “b”，……，
11 翻译成 “l”，……，25 翻译成 “z”。一个数字可能有多个翻译。
请编程实现一个函数，用来计算一个数字有多少种不同的翻译方法。*/


/*举个例子：12218
对于8这一位：

1, 它可能自己单独翻译，因此12218的翻译次数和1221的翻译次数一样，因为1221加上8仍算同一种翻译。
2,它也可以和前面一位1一起组合翻译18， 这个时候要判断这个组合翻译是否在我们规定的范围内：10~25。
如果不满足，情况2就算进去；
如果满足，则有：因此分成了122和18两部分，因为18是组合在一起的，就可以看成一个整体，和情况1一样，这个时候12218的翻译次数和122翻译次数一样，因为122加上18仍算同一种翻译。
因此，对于加上8这一位的翻译次数，也就是前5个字符的翻译次数，应该是情况1和情况2的和。
总结：

前i个字符的翻译次数：f(i)
前i - 1个字符的翻译次数：f(i - 1)
前i - 2个字符的翻译次数：f(i - 2)
对应上面说的两种情况：
情况1： f(i) = f(i - 1)
情况2： f(i) = f(i - 2)
因此：
f(i) = f(i - 1) + f(i - 2)*/

/*简单来说状态转移方程：
						dp[i] = dp[i-1]  if nums[i] 和nums[i-1]  不能合成一个字符
						dp[i] = dp[i-1] + dp[i-2]  if nums[i] 和nums[i-1]  能合成一个字符*/


class Solution {
public:
	int translateNum(int num) {

		vector<int> bit;

		while (num)
		{
			int ix = num % 10;
			bit.push_back(ix);
			num /= 10;
		}

		int len = bit.size();
		if (len == 1) return 1;
		reverse(bit.begin(), bit.end());
		vector<int> dp(len + 1, 0);

		dp[0] = 1;
		
		for (int i = 1; i <= len; i++)
		{
			dp[i] = dp[i - 1];

			if (i > 1 && bit[i - 2] * 10 + bit[i - 1] <= 25 && bit[i - 2] != 0)
				dp[i] = dp[i - 1] + dp[i - 2];


		}

		return dp[len];



	}
};


class Solution {
public:
	int translateNum(int num) {
		//方法一：动态规划
		string nums = to_string(num);
		//int dp[nums.size() + 1] = { 0 };//数组中存储的是前i个字符翻译的个数
		vector<int> dp(nums.size() + 1, 0);
		dp[0] = 1;//认为空字符串也可以翻译一种

		for (auto i = 1; i <= nums.size(); i++)
		{
			//当前字符单独翻译时
			if (nums[i - 1] >= '0' && nums[i - 1] <= '9')
				dp[i] =  dp[i - 1];
			//当前字符和前一个字符组合翻译时
			if (i > 1)
			{
				int temp = (nums[i - 2] - '0') * 10 + (nums[i - 1] - '0');
				if (temp >= 10 && temp <= 25) //如果可以组合翻译
					dp[i] = dp[i] + dp[i - 2];
			}
		}
		return dp[nums.size()];

	}
};