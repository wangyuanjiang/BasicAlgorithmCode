#include "JZOff.h"

class solution {

public:
	ListNode* reverseList(ListNode* head) {

		if (head == NULL || head->next == NULL)  //递归出口
			return head;

		ListNode* tail = reverseList(head->next);  // 让head的子链表再去进行反转

		head->next->next = head;	////实现链表指针指向反转，添加反向指针

		head->next = NULL; // 让头结点的下一个指向null，断开原指向指针

		return tail;

	}
};


class solution {

public:
	ListNode* reverseList(ListNode* head) {

		if (head == NULL || head->next == NULL)  
			return head;

		ListNode* cur = NULL;
		ListNode* pre = head;

		while (pre)
		{
			ListNode* tem = pre->next; //先记录per->next;
			pre->next = cur;	//调整pre->next的指向

			cur = pre;	//移动cur
			
			pre = tem; //移动pre
		}

		return cur;
	}
};


