
#include<iostream>
#include<queue>
using namespace std;

//��Ϊԭʼ��queue���Ƚ��ȳ�������Ҫͨ��queueʵ��ջ����ÿһ��push����Ԫ��xʱ���轫ǰ���Ԫ���Ƶ�x�ĺ��棬
//���������ʹ��q.push(q.front()); q.pop();


class MyStack {
	queue<int> nums;
public:
	/** Initialize your data structure here. */
	MyStack() {
		//nothing to do
	}

	/** Push element x onto stack. */
	void push(int x) {
		nums.push(x);
		//��ǰ���size-1��Ԫ�طŵ�����ȥ
		for (int i = 0; i < nums.size() - 1; i++) {
			nums.push(nums.front());
			nums.pop();
		}
	}

	/** Removes the element on top of the stack and returns that element. */
	int pop() {
		int num = nums.front();
		nums.pop();
		return num;
	}

	/** Get the top element. */
	int top() {
		return nums.front();
	}

	/** Returns whether the stack is empty. */
	bool empty() {
		return nums.empty();
	}
};

