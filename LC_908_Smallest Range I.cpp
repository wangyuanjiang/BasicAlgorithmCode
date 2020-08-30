
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
/*给定一个整数数组 A，对于每个整数 A[i]，我们可以选择任意 x 满足 -K <= x <= K，并将 A[i] 加上x。

在此过程之后，我们得到一些数组 B。

返回 B 的最大值和 B 的最小值之间可能存在的最小差值。

*/

//我们找到当前状态的最小值与最大值 然后让最小值 +K 最大值 -K 然后在比较两个值的差,如果差 <0 那么证明可以取其中某个值使得所有的数字都调整为那个数字,从而差值为 0

/*假设 A 是原始数组，B 是修改后的数组，我们需要最小化 max(B) - min(B)，也就是分别最小化 max(B) 和最大化 min(B)。

max(B) 最小可能为 max(A) - K，因为 max(A) 不可能再变得更小。同样，min(B) 最大可能为 min(A) + K。所以结果 max(B) - min(B) 至少为 ans = (max(A) - K) - (min(A) + K)。

我们可以用一下修改方式获得结果（如果 ans >= 0）：

如果A[i]≤min(A)+K，那么 B[i] = min(A)+K
如果A[i]≥max(A)−K，那么 B[i] = max(A)−K
否则 B[i] =A[i]。
如果 ans < 0，最终结果会有 ans = 0，同样利用上面的修改方式。
*/

//如果max(A) - min(A)>2K,那么结果为max(A) - min(A)-2K；如果max(A) - min(A)<=2K,总有办法使得结果为0；
class Solution {
public:
	int smallestRangeI(vector<int>& A, int K) {
		sort(A.begin(), A.end());
		size_t len = A.size();
		return A[len - 1] - A[0] - 2 * K > 0 ? A[len - 1] - A[0] - 2 * K : 0;

	}
};