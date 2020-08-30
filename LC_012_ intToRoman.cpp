#include<iostream>
#include<algorithm>
#include<vector>
#include<map>;
using namespace std;
class C1 {// ¼ò½à°æ±¾
	string bit1[10]{ "", "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX" };
	string bit10[10]{ "", "X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC" };
	string bit100[10]{ "", "C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM" };
	string bit1000[4]{ "", "M", "MM", "MMM" };
	string intToRoman(int num) {
		return bit1000[num / 1000] + bit100[num % 1000 / 100] + bit10[num % 100 / 10] + bit1[num % 10];
	}
};

class Solution {
public:
	string intToRoman(int num) {
		string s;
		map<int, int> map;
		int b = 1;
		while (num > 0) {
			map[b] = num % 10;
			num = num / 10;
			b = b * 10;
		}
		if (map.count(1000)) {

			for (int i = 0; i < map[1000]; i++)
				s.push_back('M');
		}
		if (map.count(100)) {
			if (map[100] < 4)
				for (int i = 0; i < map[100]; i++)
					s.push_back('C');
			else if (map[100] == 4) {
				s.push_back('C');
				s.push_back('D');
			}

			else if (map[100] == 9) {
				s.push_back('C');
				s.push_back('M');
			}
			else {
				s.push_back('D');
				for (int i = 0; i < map[100] - 5; i++)
					s.push_back('C');
			}
		}
		if (map.count(10)) {
			if (map[10] < 4)
				for (int i = 0; i < map[10]; i++)
					s.push_back('X');
			else if (map[10] == 4) {
				s.push_back('X');
				s.push_back('L');
			}

			else if (map[10] == 9) {
				s.push_back('X');
				s.push_back('C');
			}
			else {
				s.push_back('L');
				for (int i = 0; i < map[10] - 5; i++)
					s.push_back('X');
			}
		}
		if (map.count(1)) {
			if (map[1] < 4)
				for (int i = 0; i < map[1]; i++)
					s.push_back('I');
			else if (map[1] == 4) {
				s.push_back('I');
				s.push_back('V');
			}
			else if (map[1] == 9) {
				s.push_back('I');
				s.push_back('X');
			}
			else {
				s.push_back('V');
				for (int i = 0; i < map[1] - 5; i++)
					s.push_back('I');
			}
		}
		return s;
	}

};