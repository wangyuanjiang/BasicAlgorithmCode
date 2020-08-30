#include "JZOff.h"

class Solution {		//暴力解法，在每个滑动窗口里寻找最大值，然后插入res中；
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


// 时间复杂度o（n），空间复杂度为o（n）
/*思路就是采用双端队列，队列中的头节点保存的数据比后面的要大。
  比如当前假如的数据比队尾的数字大，说明当前这个数字最起码在从现在起到后面的过程中可能是最大值
  ，而之前队尾的数字不可能最大了，所以要删除队尾元素。
  此外，还要判断队头的元素是否超过滑动窗口长度，由于存储的是下标，所以可以计算得到；
  特别说明，我们在双端队列中保存的数字是传入的向量的下标；
*/
class Solution {
public:
	vector<int> maxInWindows(const vector<int>& num, unsigned int winsize)
	{
		vector<int> max_windows;
		//特殊情况
		if (num.size() <= 0 || num.size() < winsize || winsize <= 0)	return max_windows;

		deque<int> que;
		//处理前size个数据，这时候不需要输出最大值
		for (size_t i = 0; i < winsize; i++)
		{
			//待插入数据比队尾元素大，这时候将队尾元素弹出，因为原来的队尾元素不可能成为最大值 
			while (!que.empty() && num[i] >= num[que.back()])
				que.pop_back();//弹出比当前小的元素下标

			que.push_back(i);//队尾压入当前下标
		}
		//处理winsize往后的元素，这时候需要输出滑动窗口的最大值
		for (size_t i = winsize; i < num.size(); i++)
		{
			max_windows.push_back(num[que.front()]);	//将队首元素压入最大值数组中；可能会重复压入，因为同一个元素可以出现在多个滑动窗口里

			while (!que.empty() && num[i] >= num[que.back()])	//如果当前值比队列中的值大，那么队列中的值就不能再成为最大值，因此需要弹出；
				que.pop_back();

			if (!que.empty() && que.front() <= (int)(i - winsize))//判断当前下标和队首下标的差值是否超出winsize，如果超过，要删除队头元素，因为队首下标的元素和当前下标的元素不可能在一个滑动窗口里面
				que.pop_front();//删除队头元素

			que.push_back(i);//将当前下标压入队尾，因为可能在未来是最大值，
		}

		max_windows.push_back(num[que.front()]);

		return max_windows;
	}
};

