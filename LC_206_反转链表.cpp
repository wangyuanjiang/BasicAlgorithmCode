#include<iostream>
#include<vector>

using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
	ListNode* reverseList(ListNode* head) {
		ListNode* pre = NULL;
		ListNode* nex = NULL;
		while (head)
		{
			nex = head->next;  //nex 保存下一个结点
			head->next = pre;  // 当前结点的next指针指向前一个结点
			pre = head;     // 把当期结点赋值给 前一个结点
			head = nex;   // 后移当前结点
		}
		return pre;
	}
};