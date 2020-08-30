
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <algorithm>
using namespace std;

class solution
{
	void RandomShuffle(vector<int>& a, int n) { //局部洗牌函数 产生i到n-1间的随机数，然后交换
		for (int i = 0; i < n; ++i) {
			int j = rand() % (n - i) + i;// 产生i到n-1间的随机数
			swap(a[i], a[j]);
		}
	}
	
	int main_xipai() {	//主函数
		srand((unsigned)time(0)); //计算机中的随机数实际上都不是真正的随机数，如果两次给的种子一样，是会生成同样的随机序列的。 
								/*所以，一般都会以当前的时间作为种子来生成随机数，这样更加的随机。
									srand()给rand()提供种子
									srand()中的seed一般由时间函数得, eg srand((UINT)GetCurrentTime())
									srand((unsigned)time(NULL)) time()函数得到现在的系统时间...等等*/
			
		int n = 54;
		vector<int> a = {
			11, 12, 13,14, 15, 16, 17, 18, 19,110,111, 112,113,
			21,22,23,24,25,26,27,28,29, 210, 211,212,213,
			31,32, 33, 34, 35, 36, 37, 38, 39,310, 311, 312, 313,
			41,42,43,44,45,46,47,48,49,410,411, 412, 413,
			0,1 };

		RandomShuffle(a, n);
		
		// random_shuffle(a.begin(), a.end()); //使用 algorithm 的库函数 random_shuffle
		for (int i = 0; i < n; ++i)
			cout << a[i] << endl;

		//system("pause");

		return 0;
	}
};