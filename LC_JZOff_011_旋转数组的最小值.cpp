#include "JZOff.h"


/*������ε�˼���ǣ�ͨ���ų�����������СֵԪ�أ�������С��Χ�����������м���������ұߵ������ʱ�������������
1. �м�������ұߵĴ���ô�м�������������С��������С����ֻ���ܳ������м����ĺ��棬��left = mid + 1��С����
2. �м�������ұߵ�С����ô�ұߵ�������������λ������ʱ���м������������С��������right = mid ��С����
3. �м�������ұ���ȣ�����[3, 3, 3, 1, 3]��ʱ�м���������ұߵ�����Ϊ3������֪�����ǣ�
��ʱ���ǿ����ų����ұߵ�����������Ϊright = right - 1
*/

class Solution {	//���ֲ���
public:
	int minArray(vector<int>& numbers) {
		int n = numbers.size();
		int left = 0, right = n - 1;
		while (left < right) {
			int mid = (left + right) >> 1;
			if (numbers[mid] > numbers[right]) left = mid + 1;
			else if (numbers[mid] == numbers[right]) right--;
			else right = mid;
		}
		return numbers[left];
	}
};

class Solution {	//myself�� ������������
public:
	int minArray(vector<int>& numbers) {


		for (int i = 0; i < numbers.size() - 1; i++)
		{
			if (numbers[i] > numbers[i + 1])
			{
				return numbers[i + 1];
			}
		}

		return numbers[0] > numbers[numbers.size() - 1] ? numbers[numbers.size() - 1] : numbers[0];

	}
};

