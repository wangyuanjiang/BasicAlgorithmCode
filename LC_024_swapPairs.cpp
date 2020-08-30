
#include <iostream>

#include"ListNode.h";
class Solution {
public:
	ListNode* swapPairs(ListNode* head) {
		ListNode* dummy = new ListNode(0);
		ListNode* pre = dummy;
		dummy->next = head;

		ListNode* cur = head;

		while (cur != NULL)
		{
			ListNode* next = cur->next;
			if (next == NULL)
				break;

			pre->next = next;
			cur->next = next->next;
			next->next = cur;

			pre = cur;
			cur = cur->next;
		}

		return dummy->next;

	}
};

