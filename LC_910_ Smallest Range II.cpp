/*题目描述
给定一个整数数组 A，对于每个整数 A[i]，我们可以选择 x = -K 或是 x = K，并将 x 加到 A[i] 中。

在此过程之后，我们得到一些数组 B。

返回 B 的最大值和 B 的最小值之间可能存在的最小差值。
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/*int min(int a, int b)
{
	return a < b ? a : b;
}*/
//枚举
/*我们肯定期望在较小的数字上增加 K，在较大的数组上减少 K，所以首先将数组 A 从小到大排序。
初始化答案为 A[n - 1] - A[0]；然后依次枚举每个位置 i，计算此时的最小值 min(A[0] + K, A[i + 1] - K) 和最大值 max(A[i] + K, A[n - 1] - K)，
然后更新答案。*/
//要想使得结果最小，就要使得最小值达到最大，最大值达到最小；
// a[0]肯定是要加上K，a[n-1]肯定是要减去K;但是a[0]+K之后可能就不是最小值了，同理a[n-1]-K之后就可能不是最大值了

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
			int minr = min(A[0] + K, A[i + 1] - K); //最小值里最大的
			int maxr = max(A[i] + K, A[n - 1] - K); //最大值里最小的
			ans = min(ans, maxr - minr);
		}

		return ans;
	}
};