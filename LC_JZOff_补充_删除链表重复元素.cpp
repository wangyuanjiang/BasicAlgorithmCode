
#include "JZOff.h"



class Solution {
public:
	ListNode* deleteDuplication(ListNode* pHead)
	{
		
		if (pHead == nullptr && pHead->next == nullptr)
			return pHead;
		 auto res = new ListNode(-1);	//新建结点，防止头结点被删除
		 res->next = pHead;				//新建结点的next指针指向头结点

		ListNode *pre = res;	//改成pre=res->next, 就不对
		ListNode *pcur = pHead;	//改成cur=pre,或者cur= pre->next也不对
		ListNode *pnext = pcur->next;

		while (pcur)
		{
			pnext = pcur->next;

			if (pcur->val == pnext->val)
			{
				while (pnext && pnext->val == pcur->val)
						pnext = pnext->next;
				
				pre->next = pnext;
				pcur = pnext;
			}
			else
			{
				pre = pre->next;
				pcur = pcur->next;
			}

			return res->next;
		}
	}
};


class Solution {//递归
public:
	ListNode* deleteDuplicates(ListNode* pHead) {

		if (pHead == NULL || pHead->next == NULL)
			return pHead;

		ListNode* current;

		if (pHead->next->val == pHead->val)	//相等的时先移动current直到不等，再递归
		{
			current = pHead->next->next;

			while (current && current->val == pHead->val)
				current = current->next;

			return deleteDuplicates(current);
		}
		else    //不等的时候直接移动curreent， 然后进行递归调用deleteDuplicates(current)，将其赋值给pHead->next;
		{
			current = pHead->next;
			pHead->next = deleteDuplicates(current);

			return pHead;
		}

	}
};