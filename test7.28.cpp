#include <iostream>

#include <stack>
#include <vector>
#include <queue>
using namespace std;
struct TreeNode
{
	int val;
	TreeNode *left;
	TreeNode *right;
	//TreeNode(int x) :val(x), left(NULL), right(NULL);
};

class Node
{
public:
	int data;     // ˝æ›”Ú
	Node * next;  //÷∏’Î”Ú
};

int main() {

	vector<int> a, b;
	int ix, iy;
	while (cin >> ix)
		a.push_back(ix);

	while (cin >> iy)
	{
		b.push_back(iy);

	}

	size_t i = 1, left, right;
	while (i < a.size()) {
		if (a[i] > a[i - 1])
			i++;


		else {
			left = i - 1;
			right = i + 1;
		}
	}

	sort(b.begin(), b.end());
	size_t j;
	bool flag=0;
	if (right <= a.size() - 1) {
		for (j = b.size() - 1; j >= 0; j--) {
			if (b[j] > a[left] && b[j] < a[right]) {
				a[i] = b[j];
				flag = 1;
				break;
			}
		}
	}
	if(right==a.size())
		for (j = b.size() - 1; j >= 0; j--) {
			if (b[j] > a[left]) {
				a[i] = b[j];
				flag = 1;
				break;
			}
		}
	
	if (flag) {
		for (j = 0; j < a.size(); j++)
			cout << a[j] << " ";
	}
	else
		cout << "NO" << endl;
}
