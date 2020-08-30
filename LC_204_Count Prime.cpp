#include <iostream>

#include <vector>

#include<algorithm>

using namespace std;

class MyClass
{
public:
	MyClass();
	~MyClass();
	int CountPrime(int n);
private:

};

MyClass::MyClass()
{
}

MyClass::~MyClass()
{
}
int MyClass::CountPrime(int n) 
{
	vector<bool> vec(n, true);
	int res = 0;
		for (int i = 2; i < sqrt(n); i++)
		{
			if (vec[i]) {
				int k = 2;
				while (k*i < n) {
					vec[k*i] = false;
					k++;
				}
			}
		}
		for (int i = 2; i < n; i++)
			if (vec[i])
				res++;
		return res;
}