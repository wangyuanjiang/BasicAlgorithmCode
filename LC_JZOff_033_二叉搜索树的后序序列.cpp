
#include "JZOff.h"


/*˼·��
��֪������ �����������һ��ֵΪroot��������������������ֵ����rootС����������ֵ����root��

���裺

1.ȷ�����ڵ�root��
2.�������У���ȥroot��㣩���ҵ���һ������root��λ�ã����λ�����Ϊ���������ұ�Ϊ��������
3.��������������������С��root��ֵ����ֱ�ӷ���false��
4.�ֱ��ж����������������Ƿ����Ƕ��������������ݹ鲽��1��2��3����

*/
class Solution {
public:
	bool verifyPostorder(vector<int>& postorder) {

		if (postorder.empty()) return true;
		int len = postorder.size();

		return isPostorder(postorder, 0, len);

	}
	bool isPostorder(vector<int>& postorder, int begin, int len) {

		if (begin > len) return true;	//������仰�ᳬʱ
		int root = postorder[len - 1];
		int i = begin;
		for (; i < len - 1; i++) {
			if (postorder[i] > root)
				break;
		}
		int j = i;
		for (; j < len - 1; j++)
		{
			if (postorder[j] < root)
				return false;
		}

		bool left = true;
		if (i > 0)
			left = isPostorder(postorder, 0, i);

		bool right = true;
		if (i < len - 1)
			right = isPostorder(postorder, i, len - i - 1);

		return left && right;
	}
};