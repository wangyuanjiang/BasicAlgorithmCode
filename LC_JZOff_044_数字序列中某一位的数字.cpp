﻿
#include"JZOff.h"

/*对于第n 位对应的数字，我们令这个数字对应的数为 target，然后分三步进行。

首先找到这个数字对应的数是几位数，用 digits 表示；
然后确定这个对应的数的数值 target；
最后确定返回值是 target 中的哪个数字。
举个栗子：

比如输入的 n 是 365：

经过第一步计算我们可以得到第 365 个数字表示的数是三位数，n = 365 - 9 - 90\times2 = 176n = 365−9−90×2 = 176，digtis = 3。这时 n = 176n = 176 表示目标数字是三位数中的第 176176 个数字。

我们设目标数字所在的数为 number，计算得到 number = 100 + 176 / 3 = 158 number = 100 + 176 / 3 = 158，idx 是目标数字在 number 中的索引，如果 idx = 0，表示目标数字是 number 中的最后一个数字。

根据步骤2，我们可以计算得到 idx = n % digits = 176 % 3 = 2，说明目标数字应该是 number = 158 中的第二个数字，即输出为 5。*/
// 如果 n%digit == 0, 那么应该是数字 number + n / digits - 1 的最后一位  !!!!!!!!!!!!!!!!!!!!

class Solution { //其实我没有理解!!!!!!!!!!
public:
	int findNthDigit(int n) {
		// 计算该数字由几位数字组成，由1位：digits = 1；2位：digits = 2...
		long base = 9, digits = 1;
		while (n - base * digits > 0) {
			n -= base * digits;
			base *= 10;
			digits++;
		}

		// 计算真实代表的数字是多少
		int idx = n % digits;  // 注意由于上面的计算，n现在表示digits位数的第n个数字

		if (idx == 0)idx = digits;//如果idx==0，应该是
		long number = 1;

		for (int i = 1; i < digits; i++)
			number *= 10;
		number += (idx == digits) ? n / digits - 1 : n / digits;//

		// 从真实的数字中找到我们想要的那个数字
		for (int i = idx; i < digits; i++) number /= 10;
		return number % 10;
	}
};

class Solution {		//myself 超时了
public:
	int findNthDigit(int n) {
		string s;
		int i = 0, count = 0;
		while (s.size() <= n + 1)
		{
			s += to_string(i);
			i++;
		}

		int res = s[n] - '0';

		return res;
	}
};

class Solution {		//myself 超时了
public:
	int findNthDigit(int n) {

		int base = 9, digit = 1;
		while (n - base * digit > 0)
		{
			n -= base * digit;
			base *= 10;
			digit++;
		}

		int idx = n % digit;

		if (idx == 0) idx = digit;

		int number = 1;

		for (int i = 0; i < digit - 1; i++)
		{
			number *= 10;

		}

		number += (idx == digit ? n / digit - 1 : n / digit);

		for (int i = idx; i < digit; i++)
			number /= 10;

		return number % 10;
	}

	};


