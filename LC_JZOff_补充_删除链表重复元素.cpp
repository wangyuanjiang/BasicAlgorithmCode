
#include "JZOff.h"



class Solution {
public:
	ListNode* deleteDuplication(ListNode* pHead)
	{
		
		if (pHead == nullptr && pHead->next == nullptr)
			return pHead;
		 auto res = new ListNode(-1);	//�½���㣬��ֹͷ��㱻ɾ��
		 res->next = pHead;				//�½�����nextָ��ָ��ͷ���

		ListNode *pre = res;	//�ĳ�pre=res->next, �Ͳ���
		ListNode *pcur = pHead;	//�ĳ�cur=pre,����cur= pre->nextҲ����
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


class Solution {//�ݹ�
public:
	ListNode* deleteDuplicates(ListNode* pHead) {

		if (pHead == NULL || pHead->next == NULL)
			return pHead;

		ListNode* current;

		if (pHead->next->val == pHead->val)	//��ȵ�ʱ���ƶ�currentֱ�����ȣ��ٵݹ�
		{
			current = pHead->next->next;

			while (current && current->val == pHead->val)
				current = current->next;

			return deleteDuplicates(current);
		}
		else    //���ȵ�ʱ��ֱ���ƶ�curreent�� Ȼ����еݹ����deleteDuplicates(current)�����丳ֵ��pHead->next;
		{
			current = pHead->next;
			pHead->next = deleteDuplicates(current);

			return pHead;
		}

	}
};