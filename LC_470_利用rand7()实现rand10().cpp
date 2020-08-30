#include <iostream>
#include <ctime>
#include <cstdlib>

// The rand7() API is already defined for you.
// int rand7();
// @return a random integer in the range 1 to 7

class Solution {
public:
	int rand10() {

		int col = rand7();
		int row = rand7();

		int index = col + (row - 1) * 7;
		do {

			col = rand7();
			row = rand7();
			index = col + (row - 1) * 7;
		} while (index > 40);

		return 1 + (index - 1) % 10;
	}

private:
	
	int rand7() {

		srand((unsigned int) time(0));

		return rand() % (7 - 1 + 1) + 1; //  rand() % (end - sttart + 1) + start  产生 [start, end] 的随机数
	}
};