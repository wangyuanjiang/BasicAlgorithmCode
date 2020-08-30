#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
using namespace std;
int Fib1(int n) {//暴力递归；
	if (n == 1 || n == 2)
		return 1;
	return Fib1(n - 1) + Fib1(n - 2);

 }


/*int Fib2(int n) {//动态规划，带备忘录
	if (n<1)
		return 0;
	vector<int> memory(n + 1, 0);
		return Record(memory, n);
}*/

int Record(vector<int> &a, int n) {//动态规划，带备忘录
	if (n == 1 || n == 2)
		return 1;
	if (a[n] == 0)
		a[n] = Record(a, n - 1) + Record(a, n - 2);
	if (a[n] != 0)
		return a[n];
}

int Fib2(int n) {//动态规划，带备忘录
	if (n < 1)
		return 0;
	vector<int> memory(n + 1, 0);
	return Record(memory, n);
}
int Fib3(int n) {   //动态规划，自低向上
	vector<int> dp(n + 1, 0);
	dp[1] = 1; dp[2] = 1;
	for (int i = 3; i <= n; i++)
		dp[i] = dp[i - 1] + dp[i - 2];
	return dp[n];
}




#include <iostream>
using namespace std;
unsigned int GetTestNum() {
	static unsigned int a = 0;
	static unsigned int b = 1;
	int c = a + b;
	a = b;
	b = c;
	return c;
}
int main_feb022401(int argc, char* argv[]) {
	int n,res;
	for (int i = 0; i < n; i++) {
		 res = GetTestNum();
	}
	cout << res << endl;
	return 0;
}