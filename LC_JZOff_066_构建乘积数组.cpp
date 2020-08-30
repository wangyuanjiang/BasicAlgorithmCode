
#include "JZOff.h"


/*����һ������A[0,1,...,n-1],�빹��һ������B[0,1,...,n-1],
����B�е�Ԫ��B[i]=A[0]*A[1]*...*A[i-1]*A[i+1]*...*A[n-1]������ʹ�ó�����*/

/*--------------------------��������----------------------------*/
/*---------------------�ֿ����������ܹ����͸��Ӷ�------------------------*/
class Solution {
public:
	vector<int> multiply(const vector<int>& A) {

		int len = A.size();
		if (len == 0)
			return {};
		vector<int> B(len, 1);
		vector<int> D(len, 1);

		for (int i = 1; i < len; i++) //ǰ�벿��
		{
			B[i] = B[i - 1] * A[i - 1];
		}

		for (int i = len - 2; i >= 0; i--) // ��벿��
		{
			D[i] = D[i + 1] * A[i + 1];

		}
		for (int i = 0; i < len; i++)  //�����ֳ�����
			B[i] *= D[i];

		return B;
	}
};