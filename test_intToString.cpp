#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

int main_teintt0string(){
	int sum = 123456;
	string str;
	while(sum > 0){
	char ch = sum % 10 + '0';
	str.push_back(ch);
	sum = sum / 10;
	}
	reverse(str.begin(), str.end());
	cout << str;

	system("pause");
	return 0;
}