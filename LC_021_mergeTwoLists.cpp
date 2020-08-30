
#include <iostream>

#include <vector>
#include <map>
using namespace std;

//����һ���ڵ���
typedef struct ListNode
{
	int val;     //������
	ListNode * next;  //ָ����
	ListNode(int x) :val(x), next ( NULL){}
}ListNode, *LinkList;
 //ListNode(int x): data(x),
class Solution {//myself
public:
	ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
		ListNode *L;
		ListNode p, p1, p2;
		L = (ListNode*)malloc(sizeof(ListNode));

		p = *L;
		p1 = *l1;
		p2 = *l2;
		while (l1 != NULL && L2 != NULL) {
			if (p1->val >= p2->val) {
				p->val = p1->val;
				p->next = p2;
				p = p2;
				p2 = p2->next;
			}
			else
			{
				p->val = p2->val;
				p->next = p2;
				p = p2;
				p2 = p2->next;
			}
		}
		return L;
	}
};

class Solution {//����
public:
	ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
		ListNode *dummyHead = new ListNode(0);
		ListNode *cur = dummyHead;


		while (l1 != NULL && l2 != NULL) {
			if (l1->val > l2->val) {
				cur->next = l2;// ��L2,L1��С���Ǹ���ֵ��cur->next
				cur = cur->next;//cur ����
				l2 = l2->next;//��L2,L1��С���Ǹ����ƣ�
			}
			else {
				cur->next = l1;
				cur = cur->next;
				l1 = l1->next;
			}
		}
		if (l1 == NULL) {//Ϊ��֮�����ٱȽ�
			cur->next = l2;
		}
		else {
			cur->next = l1;
		}

		return dummyHead->next;
		// return dummyHead;  ����������ػ����ͷ��㣬��ͷ����valΪ0
	}
	
};
class Solution {
public:
	ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
		ListNode* res = new ListNode(0);
		ListNode* p = l1, *q = l2, *k = res;
		while (p && q) {
			if (!res->next) {//���Ϊ��
				if (p->val <= q->val) {
					res->next = p;
					p = p->next;
				}
				else {
					res->next = q;
					q = q->next;
				}
				k = res->next;
			}
			else {//�����Ϊ��
				if (p->val <= q->val) {
					k->next = p;
					p = p->next;
				}
				else {
					k->next = q;
					q = q->next;
				}
				k = k->next;
			}
		}
		while (q)
		{
			k->next = q;
			q = q->next;
			k = k->next;
		}
		while (p) {
			k->next = p;
			p = p->next;
			k = k->next;
		}
		return res->next;
	}
};

class Solution {
public:
	ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
		ListNode *L = new ListNode(0);
		ListNode *p, *p1, *p2;
		p = L;
		p1 = l1;
		p2 = l2;
		if (l1 == NULL && l2 == NULL) {

			L = NULL;
			return L;
		}

		while (l1 != NULL && l2 != NULL) {
			if (l1->val > l2->val) {
				p->val = l2->val;
				p->next = l2;
				p = l2;
				l2 = l2->next;
			}
			else
			{
				p->val = l1->val;
				p->next = l1;
				p = l1;
				l1 = l1->next;
			}
		}

		if (p1 == NULL) {
			p->next = l2->next;
		}
		if (p2 == NULL) {
			p->next = l1->next;
		}
		return L->next;
	}


};