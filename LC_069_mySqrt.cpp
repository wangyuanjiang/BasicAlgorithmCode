#include <iostream>
class MyClass
{
public:
	MyClass();
	~MyClass();
	int mySqrt(int x) {
		int beg = 0;
		int end = x;
		while (beg<=end)
		{
			int mid = beg + (end - beg) / 2;// 这是标准的 二分法  而不是 mid=(beg+end)/2;
			int s = x / mid;
			if (s == mid) return mid;
			if (s > mid) beg = mid + 1;
			if (s < mid) end = mid - 1;
		}
		return end;
	}

	int mySqrt1(int x) {
		int beg = 0;
		int end = x;
		while (beg <= end)
		{
			int mid = beg + (end - beg) / 2; // 标准的 二分法 
			int s = x / mid;
			int ss = x / (mid + 1);
			if (s == mid) return mid;
			if (s > mid &&ss < mid + 1) return mid; //a<sqrt(x)&&a+1>sqrt(x); => a<sqrt(x)<a+1;
			if (s > mid) beg = mid + 1;
			if (s < mid) end = mid - 1;
		}
		return 0;
	}

	int mySqrt2(int x) {
		long long beg=0;
		long long end=x/2+1;
		while (beg <= end) {
			long long mid = (beg + end) / 2;
			long long res=mid*mid;
			if (res == x) return mid;
			if (res < x) beg = mid + 1;
			if (res > x) end = mid-1;
		}
		return end;
	}

	class Solution1 {
	public:
		int mySqrt3(int x) {
			long long beg = 0;
			long long end = x / 2 + 1;
			while (beg <= end) {
				long long mid = beg+(end-beg)/2;
				long long res = mid * mid;
				if (res == x) return mid;
				if (res < x) beg = mid + 1;
				if (res > x) end = mid - 1;
			}
			return end;
		}
	};

private:

};

