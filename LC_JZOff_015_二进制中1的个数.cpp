
#include "JZOff.h"

class Solution {		//�ⷨ1��n =  n & ��n-1�� ���n���ұߵ�һ��1��Ϊ0��
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

class Solution {		//�ⷨ2����n �ֱ� �� 1,2,4��8 (��Щ�����ص��� ֻ��һλΪ1)�������㣻
public:
	int hammingWeight(uint32_t n) {

		uint32_t base = 1;
		uint32_t count = 0;
		while (base)		//����д�� n>=base;
		{
			if (n & base)
				count++;
			base = base << 1;
		}
		return count;
	}
};


class Solution {		//�ⷨ3����nÿ������һλ���ٺ�1�������㣻�������ֽⷨ�����븺��ʱ��������ѭ��
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