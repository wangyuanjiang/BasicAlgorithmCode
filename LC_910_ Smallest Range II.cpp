/*��Ŀ����
����һ���������� A������ÿ������ A[i]�����ǿ���ѡ�� x = -K ���� x = K������ x �ӵ� A[i] �С�

�ڴ˹���֮�����ǵõ�һЩ���� B��

���� B �����ֵ�� B ����Сֵ֮����ܴ��ڵ���С��ֵ��
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/*int min(int a, int b)
{
	return a < b ? a : b;
}*/
//ö��
/*���ǿ϶������ڽ�С������������ K���ڽϴ�������ϼ��� K���������Ƚ����� A ��С��������
��ʼ����Ϊ A[n - 1] - A[0]��Ȼ������ö��ÿ��λ�� i�������ʱ����Сֵ min(A[0] + K, A[i + 1] - K) �����ֵ max(A[i] + K, A[n - 1] - K)��
Ȼ����´𰸡�*/
//Ҫ��ʹ�ý����С����Ҫʹ����Сֵ�ﵽ������ֵ�ﵽ��С��
// a[0]�϶���Ҫ����K��a[n-1]�϶���Ҫ��ȥK;����a[0]+K֮����ܾͲ�����Сֵ�ˣ�ͬ��a[n-1]-K֮��Ϳ��ܲ������ֵ��

class Solution {
public:
	int smallestRangeII(vector<int>& A, int K) {
		sort(A.begin(), A.end());
		int len = A.size();
		int res = A[len - 1] - A[0];
		for (int i = 0; i < len - 1; i++) {
			int minr = min(A[0] + K, A[i + 1] - K);		
			int maxr = max(A[len - 1] - K, A[i] + K);
			res = min(res, maxr - minr);
		}
		
		return res;
	}


};

class Solution {
public:
	int smallestRangeII(vector<int>& A, int K) {

		sort(A.begin(), A.end());
		int n = A.size();
		int ans = A[n - 1] - A[0];
		for (int i = 0; i < n - 1; i++) {
			int minr = min(A[0] + K, A[i + 1] - K); //��Сֵ������
			int maxr = max(A[i] + K, A[n - 1] - K); //���ֵ����С��
			ans = min(ans, maxr - minr);
		}

		return ans;
	}
};