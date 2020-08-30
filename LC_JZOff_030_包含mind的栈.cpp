#include "JZOff.h"

class MinStack {
public:
	/** initialize your data structure here. */
	MinStack() {

	}

	void push(int x) {
		sta.push(x);
		if (minsta.empty() || (!minsta.empty() && minsta.top() >= x))  minsta.push(x);

	}

	void pop() {
		if (!sta.empty())
		{
			if (!minsta.empty() && minsta.top() == sta.top()) {
				sta.pop();
				minsta.pop();
			}
			else sta.pop();
		}


	}

	int top() {

		return sta.top();

	}

	int min() {

		return minsta.top();

	}
private:
	stack<int> sta;
	stack<int> minsta;
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->min();
 */