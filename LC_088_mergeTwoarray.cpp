#include<iostream>
#include<vector>
using namespace std;
class Solution {//myself  wrong���� ��˳�������Ĳ��������ⲻ����
public:
	void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
		size_t i = 0, j = 0;

		if (n!=0 && m!=0 &&nums1[0] > nums2[0]){
			nums1.insert(nums1.begin(), nums2[j]);//ִ��insert������ʹ�õ�����ʧЧ
			++i;
			++j;
		}
		if (n != 0) {
			
			while (1) {
				auto it = nums1.begin();
				if (nums1[i] > nums2[j] && i < n + m && j < n) {
					nums1.insert(nums1.begin() + i, nums2[j]);//ִ��insert������ʹ�õ�����ʧЧ
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
					it = nums1.insert(it, nums2[j]);//ִ��insert������ʹ�õ�����ʧЧ
					++i;
					++j;
					it++;
				}
				if (i < j + m && j < n &&nums1[i] <= nums2[j]) {
					++i;
					it++;
				}
				if (i >= m + j && j < n) {
					it = nums1.insert(it, nums2[j]);//����ֵ�� ָ�������Ԫ�صõ�������
												  //��vector ִ�в���������ʹ����ָ�������ĵ����������ã���ָ��ʧЧ����������������ֵ��ֵ��ֵ��it��������
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
class Solution {//���˵�
public:
	void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
		int k = m + n;
		while (m > 0 && n > 0) {
			if (nums1[m - 1] >= nums2[n - 1]) {
				nums1[k - 1] = nums1[m - 1]; //û���½�һ����������飬ֱ����nums1����в�������nums1��β����ʼ��ȡnums1��nums2�е����ֵ�������С�
				--k;
				--m;//ȡһ�μ�һ��
			}
			else {
				nums1[k - 1] = nums2[n - 1];
				--k;
				--n;
			}
		}
		while (n > 0) {  //���n�ȵ���0����ֱ�ӵõ��ϲ��õ����飻���m�ȵ���0��ֻ�轫nʣ�µ�Ԫ�ظ��Ƶ�nums1�м��ɡ�
			nums1[k - 1] = nums2[n - 1];
			--k;
			--n;
		}

	}
};

class Solution {
public:
	void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
		vector<int> num(m + n);//��ⷨһ���ƣ��������½�һ��vector
		int i = 0, j = 0, k = 0;
		while (i < m && j < n) {
			if (nums1[i] <= nums2[j])
				num[k++] = nums1[i++];
			else
				num[k++] = nums2[j++];
		}
		while (i < m) num[k++] = nums1[i++];
		while (j < n) num[k++] = nums2[j++];
		nums1.assign(num.begin(), num.end());//nums1.swap(num)Ҳ����
	}
};