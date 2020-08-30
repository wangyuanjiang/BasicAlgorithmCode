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
			nex = head->next;  //nex ������һ�����
			head->next = pre;  // ��ǰ����nextָ��ָ��ǰһ�����
			pre = head;     // �ѵ��ڽ�㸳ֵ�� ǰһ�����
			head = nex;   // ���Ƶ�ǰ���
		}
		return pre;
	}
};