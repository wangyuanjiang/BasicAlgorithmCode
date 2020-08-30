
#include "JZOff.h"

class Solution {		//解法1：n =  n & （n-1） 会把n最右边的一个1变为0；
public:
	int hammingWeight(uint32_t n) {

		uint32_t base = 1;
		uint32_t count = 0;
		while (n) 
		{
			count++;

			n = n & (n - 1);
		}
		return count;
	}
};

class Solution {		//解法2：将n 分别 和 1,2,4，8 (这些数的特点是 只有一位为1)做与运算；
public:
	int hammingWeight(uint32_t n) {

		uint32_t base = 1;
		uint32_t count = 0;
		while (base)		//不能写成 n>=base;
		{
			if (n & base)
				count++;
			base = base << 1;
		}
		return count;
	}
};


class Solution {		//解法3：将n每次右移一位，再和1做与运算；但是这种解法当输入负数时会陷入死循环
public:
	int hammingWeight(uint32_t n) {

		uint32_t base = 1;
		uint32_t count = 0;
		while (n)
		{
			if (n & 1)
				count++;

			n = n >> 1;
		}
		return count;
	}
};