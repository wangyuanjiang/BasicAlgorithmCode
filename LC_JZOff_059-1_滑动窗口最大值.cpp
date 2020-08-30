#include "JZOff.h"

class Solution {		//�����ⷨ����ÿ������������Ѱ�����ֵ��Ȼ�����res�У�
public:
	vector<int> maxSlidingWindow(vector<int>& nums, int k) {

		vector<int> res;
		if (nums.size() == 0) {
			return res;
		}

		auto left = nums.begin();
		auto right = nums.begin() + k;

		while (1)
		{
			int max = *max_element(left, right);
			res.push_back(max);
			if (right == nums.end())
				break;

			left++;
			right++;
		}

		return res;
	}
};


// ʱ�临�Ӷ�o��n�����ռ临�Ӷ�Ϊo��n��
/*˼·���ǲ���˫�˶��У������е�ͷ�ڵ㱣������ݱȺ����Ҫ��
  ���統ǰ��������ݱȶ�β�����ִ�˵����ǰ��������������ڴ������𵽺���Ĺ����п��������ֵ
  ����֮ǰ��β�����ֲ���������ˣ�����Ҫɾ����βԪ�ء�
  ���⣬��Ҫ�ж϶�ͷ��Ԫ���Ƿ񳬹��������ڳ��ȣ����ڴ洢�����±꣬���Կ��Լ���õ���
  �ر�˵����������˫�˶����б���������Ǵ�����������±ꣻ
*/
class Solution {
public:
	vector<int> maxInWindows(const vector<int>& num, unsigned int winsize)
	{
		vector<int> max_windows;
		//�������
		if (num.size() <= 0 || num.size() < winsize || winsize <= 0)	return max_windows;

		deque<int> que;
		//����ǰsize�����ݣ���ʱ����Ҫ������ֵ
		for (size_t i = 0; i < winsize; i++)
		{
			//���������ݱȶ�βԪ�ش���ʱ�򽫶�βԪ�ص�������Ϊԭ���Ķ�βԪ�ز����ܳ�Ϊ���ֵ 
			while (!que.empty() && num[i] >= num[que.back()])
				que.pop_back();//�����ȵ�ǰС��Ԫ���±�

			que.push_back(i);//��βѹ�뵱ǰ�±�
		}
		//����winsize�����Ԫ�أ���ʱ����Ҫ����������ڵ����ֵ
		for (size_t i = winsize; i < num.size(); i++)
		{
			max_windows.push_back(num[que.front()]);	//������Ԫ��ѹ�����ֵ�����У����ܻ��ظ�ѹ�룬��Ϊͬһ��Ԫ�ؿ��Գ����ڶ������������

			while (!que.empty() && num[i] >= num[que.back()])	//�����ǰֵ�ȶ����е�ֵ����ô�����е�ֵ�Ͳ����ٳ�Ϊ���ֵ�������Ҫ������
				que.pop_back();

			if (!que.empty() && que.front() <= (int)(i - winsize))//�жϵ�ǰ�±�Ͷ����±�Ĳ�ֵ�Ƿ񳬳�winsize�����������Ҫɾ����ͷԪ�أ���Ϊ�����±��Ԫ�غ͵�ǰ�±��Ԫ�ز�������һ��������������
				que.pop_front();//ɾ����ͷԪ��

			que.push_back(i);//����ǰ�±�ѹ���β����Ϊ������δ�������ֵ��
		}

		max_windows.push_back(num[que.front()]);

		return max_windows;
	}
};

