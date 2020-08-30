#include <iostream>

#include <vector>
#include <map>
using namespace std;

vector<int> TowSum(vector<int> &nums, int target)
{
	map<int, int> map1;
	vector<int> res;
	size_t i;
	for (i = 0; i < nums.size(); ++i) {
		map1[nums[i]] = i;//key 为nums[i],value 的值为 下标；
	}
	for (i = 0; i < nums.size(); ++i) {
		int v = target - nums[i];
		if (map1.count(v) && map1[v] != i) {//存在且不是本身
			res.push_back(i);
			res.push_back(map1[v]);
		}
	}
	return res;

}
int main() {
	vector<int> nums;
	int target;
	cout << "please entry vector " << endl;
	while (cin >> target)
		nums.push_back(target);
	cout << "please entry target" << endl;
	vector<int> res = TowSum(nums, target);
	for (auto &it : res)
		cout << it << endl;
	return 0;
}