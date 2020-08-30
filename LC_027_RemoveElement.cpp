#include<iostream>
#include<vector>
using namespace std;

class Solution { //myself 
public:
	int removeElement(vector<int>& nums, int val) {
		// vector<int>::size_type i;
		auto it = nums.begin();
		while (it != nums.end()) {
			if (*it == val)
				it = nums.erase(it);
			if (*it != val)
				it++;
		}
		for (auto j : nums)
			cout << j << " ";
		cout << endl;
		return nums.size();
	}
};

class Solution {//other  people
public:
	int removeElement(vector<int>& nums, int val) {
		int len = 0;
		for (int i = 0; i < nums.size(); i++) {
			if (nums[i] != val) nums[len++] = nums[i];
		}
		return len;
	}
};