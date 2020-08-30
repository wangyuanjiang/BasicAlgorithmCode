#include "JZOff.h"

class solution {

public:
	ListNode* reverseList(ListNode* head) {

		if (head == NULL || head->next == NULL)  //�ݹ����
			return head;

		ListNode* tail = reverseList(head->next);  // ��head����������ȥ���з�ת

		head->next->next = head;	////ʵ������ָ��ָ��ת����ӷ���ָ��

		head->next = NULL; // ��ͷ������һ��ָ��null���Ͽ�ԭָ��ָ��

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
			ListNode* tem = pre->next; //�ȼ�¼per->next;
			pre->next = cur;	//����pre->next��ָ��

			cur = pre;	//�ƶ�cur
			
			pre = tem; //�ƶ�pre
		}

		return cur;
	}
};


