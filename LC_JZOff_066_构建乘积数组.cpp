
#include "JZOff.h"


/*给定一个数组A[0,1,...,n-1],请构建一个数组B[0,1,...,n-1],
其中B中的元素B[i]=A[0]*A[1]*...*A[i-1]*A[i+1]*...*A[n-1]。不能使用除法。*/

/*--------------------------容易理解的----------------------------*/
/*---------------------分开来做，就能够降低复杂度------------------------*/
class Solution {
public:
	vector<int> multiply(const vector<int>& A) {

		int len = A.size();
		if (len == 0)
			return {};
		vector<int> B(len, 1);
		vector<int> D(len, 1);

		for (int i = 1; i < len; i++) //前半部分
		{
			B[i] = B[i - 1] * A[i - 1];
		}

		for (int i = len - 2; i >= 0; i--) // 后半部分
		{
			D[i] = D[i + 1] * A[i + 1];

		}
		for (int i = 0; i < len; i++)  //两部分乘起来
			B[i] *= D[i];

		return B;
	}
};