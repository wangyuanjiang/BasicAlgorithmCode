#include<iostream>
#include<vector>
using namespace std;
class Solution {//myself  wrong！！ 对顺序容器的插入操作理解不深入
public:
	void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
		size_t i = 0, j = 0;

		if (n!=0 && m!=0 &&nums1[0] > nums2[0]){
			nums1.insert(nums1.begin(), nums2[j]);//执行insert操作会使得迭代器失效
			++i;
			++j;
		}
		if (n != 0) {
			
			while (1) {
				auto it = nums1.begin();
				if (nums1[i] > nums2[j] && i < n + m && j < n) {
					nums1.insert(nums1.begin() + i, nums2[j]);//执行insert操作会使得迭代器失效
					++i;
					++j;
				}
				if (nums1[i] <= nums2[j] && i < m + j && j < n) {
					++i;
				}
				if (i >= m + j && j < n) {
					nums1.insert(nums1.begin() + i, nums2[j]);
					++j;
					++i;
				}
				if (i == n + m || j == n)
					break;
			}
			nums1.erase(nums1.begin() + n + m, nums1.end());
		}
		if (nums2.size() == 0)
			return;
	}

}; 


class Solution {// myself   Correct
public:
	void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
		size_t i = 0, j = 0;
		if (m == 0 && n != 0)
			swap(nums1, nums2);
		
		if (n != 0 && m != 0) {
			auto it = nums1.begin();
			while (1) {

				if (i <= n + m && j <n &&nums1[i] > nums2[j]) {
					it = nums1.insert(it, nums2[j]);//执行insert操作会使得迭代器失效
					++i;
					++j;
					it++;
				}
				if (i < j + m && j < n &&nums1[i] <= nums2[j]) {
					++i;
					it++;
				}
				if (i >= m + j && j < n) {
					it = nums1.insert(it, nums2[j]);//返回值是 指向新添加元素得迭代器。
												  //对vector 执行插入操作后会使所有指向容器的迭代器，引用，和指针失效，因此如果不将返回值赋值赋值给it，则会出错
					++j;
					++i;
					it++;
				}
				if (i == n + m || j == n)
					break;
			}
			nums1.erase(nums1.begin() + n + m, nums1.end());
		}
		if (nums2.size() == 0)
			return;
	}

};
class Solution {//别人的
public:
	void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
		int k = m + n;
		while (m > 0 && n > 0) {
			if (nums1[m - 1] >= nums2[n - 1]) {
				nums1[k - 1] = nums1[m - 1]; //没有新建一个额外的数组，直接在nums1里进行操作，从nums1的尾部开始，取nums1和nums2中的最大值放入其中。
				--k;
				--m;//取一次减一次
			}
			else {
				nums1[k - 1] = nums2[n - 1];
				--k;
				--n;
			}
		}
		while (n > 0) {  //如果n先到达0就能直接得到合并好的数组；如果m先到达0，只需将n剩下的元素复制到nums1中即可。
			nums1[k - 1] = nums2[n - 1];
			--k;
			--n;
		}

	}
};

class Solution {
public:
	void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
		vector<int> num(m + n);//与解法一类似，不过是新建一个vector
		int i = 0, j = 0, k = 0;
		while (i < m && j < n) {
			if (nums1[i] <= nums2[j])
				num[k++] = nums1[i++];
			else
				num[k++] = nums2[j++];
		}
		while (i < m) num[k++] = nums1[i++];
		while (j < n) num[k++] = nums2[j++];
		nums1.assign(num.begin(), num.end());//nums1.swap(num)也可以
	}
};