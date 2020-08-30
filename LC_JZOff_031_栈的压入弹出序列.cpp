#include "JZOff.h"


/*���������������У���һ�����б�ʾջ��ѹ��˳�����жϵڶ��������Ƿ�Ϊ��ջ�ĵ���˳��
����ѹ��ջ���������־�����ȡ����磬���� {1,2,3,4,5} ��ĳջ��ѹջ���У����� {4,5,3,2,1} 
�Ǹ�ѹջ���ж�Ӧ��һ���������У�
�� {4,3,5,1,2} �Ͳ������Ǹ�ѹջ���еĵ������С�*/

class Solution {
public:
	bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {

		stack<int> tem;

		int len = pushed.size();
		if (len != popped.size())    return false;
		int p1 = 0, p2 = 0;
		for (; p1 < len; p1++) {  //���򣬲��ǵ���

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