#include "JZOff.h"


/*输入两个整数序列，第一个序列表示栈的压入顺序，请判断第二个序列是否为该栈的弹出顺序。
假设压入栈的所有数字均不相等。例如，序列 {1,2,3,4,5} 是某栈的压栈序列，序列 {4,5,3,2,1} 
是该压栈序列对应的一个弹出序列，
但 {4,3,5,1,2} 就不可能是该压栈序列的弹出序列。*/

class Solution {
public:
	bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {

		stack<int> tem;

		int len = pushed.size();
		if (len != popped.size())    return false;
		int p1 = 0, p2 = 0;
		for (; p1 < len; p1++) {  //正序，不是倒序

			tem.push(pushed[p1]);
			while (!tem.empty() && p2 < len && popped[p2] == tem.top())
			{
				tem.pop();
				p2++;
			}

		}

		if (tem.empty())     return true;

		return false;
	}
};