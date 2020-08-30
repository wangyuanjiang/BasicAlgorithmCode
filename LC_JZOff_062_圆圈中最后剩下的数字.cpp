

#include "JZOff.h"

class Solution {		//�ⷨһ�� �������� ��ʱ����������
public:
	int lastRemaining(int n, int m) {
		if (n <= 0 || m < 0)
			throw "Invalid input";

		list<int> loop(n, 0);
		auto it = loop.begin();
		for (int i = 0; i < n; i++)
		{
			*it = i;
			it++;
		}

		auto current = loop.begin();

		while (loop.size() > 1) {

			for (int i = 1; i < m; i++)
			{
				current++;
				if (current == loop.end())
					current = loop.begin();
			}
			auto next = current;
			next++;

			//loop.erase(current);
			//current =next; 
			if (next == loop.end())
				next = loop.begin();

			loop.erase(current);
			current = next;

		}

		return *current;

	}
};



class Solution {		//�ⷨ����Լɪ��  f(n,m)��ʾÿ����n�����֣�0,1������n-1��ÿ��ɾ����m��Ԫ�����ʣ�µ����֣�
	//�ܽ���ƹ�ʽΪ��
	//*1 > ��n = 1ʱ��f(n, m) = 0;
	//*2 > ��n > 1ʱ��f(n, m) = (f(n - 1, m) + m) % n

		
public:
	int lastRemaining(int n, int m) {
		if (n <= 0 || m < 1)
			throw "Invalid input";

		int res = 0;
		for (int i = 2; i <= n; i++)
			res = (res + m) % i;

		return res;
	}
};
