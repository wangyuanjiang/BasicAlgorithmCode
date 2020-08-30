
#include <iostream>
#include<vector>
#include <algorithm>
#include <queue>
using namespace std;
/*����һ������ n ���������������һ�������� s ���ҳ���������������� �� s �ĳ�����С������������ĳ��ȡ�
��������ڷ������������������飬���� 0��*/

class Solution {	//myself
public:
	int minSubArrayLen(int s, vector<int>& nums) {

		if (nums.empty())    return 0;
		deque<int> que;
		int res = nums.size(), sum = 0;
		bool flag = false;
		for (int i = 0; i < nums.size(); i++) {

			//if(sum < s){
			que.push_back(nums[i]);
			sum += nums[i];
			//}

			while (!que.empty() && sum - que.front() >= s) {
				sum = sum - que.front();
				que.pop_front();

			}

			if (sum >= s) {
				flag = true;
				if (res > que.size())
					res = que.size();
			}

		}

		return (flag ? res : 0);
	}

};

/*
1��ʼright���һ�����ʹ�ͱ��
2��ǡ�ô��ڵ���sʱ����¼�����������������鳤��res��
	��res������ֵ�����ж���ֵ�Ƿ�С�ھ�ֵ�����ǣ�����res��i ���һ���
3�ж��Ƿ��Դ��ڵ���s
���ǣ��ظ�����2��3������ת����1��ֱ���ұ߿򵽴����ұ�

*/
class Solution {  //���˵�
public:
	int minSubArrayLen(int s, vector<int>& nums) {
		if (nums.empty()) return 0;
		int res = nums.size() + 1;
		int i = 0, right = 0, sum = 0;
		while (right < nums.size())	 //�������ұ߿��ܳ�������
		{
			if (sum + nums[right] < s) {	//������֮��ĺ�С��s���ұ߿����ƣ�sum����
				sum += nums[right];
				right++;
			}


			else {						//������֮��ĺʹ��ڵ���s����߿����ƣ�sum��С
				if (res > right - i)  res = right - i + 1;	//����ǰ���������������������res�ڼ�¼�ĳ��ȸ�С�������resֵ

				sum -= nums[i];
				i++;
			}
		}
		return (res > nums.size() ? 0 : res);	//��Ҫ�ж��Ƿ����
	}

};


class Solution {  //˫ָ��
public:
	int minSubArrayLen(int s, vector<int>& nums) {

		int res = nums.size() + 1;
		int left = 0;
		int sum = 0;
		for (int i = 0; i < nums.size(); i++) {
		
			sum += nums[i];
			while (sum >=s)
			{
				res = min(res, i - left + 1);
				sum -= nums[left++];
			}
		}

		return (res > nums.size() ? 0 : res);
	}
};