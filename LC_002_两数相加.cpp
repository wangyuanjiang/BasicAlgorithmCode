
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


/*��������?�ǿ� ������������ʾ�����Ǹ������������У����Ǹ��Ե�λ���ǰ�������ķ�ʽ�洢�ģ��������ǵ�ÿ���ڵ�ֻ�ܴ洢һλ���֡�

��������ǽ��������������������᷵��һ���µ���������ʾ���ǵĺ͡�

�����Լ���������� 0 ֮�⣬���������������� 0?��ͷ��

ʾ����

���룺(2 -> 4 -> 3) + (5 -> 6 -> 4)
�����7 -> 0 -> 8
ԭ��342 + 465 = 807

*/

  struct ListNode {
      int val;
     ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
  };
 
class Solution {
public:
	ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {

		auto head = new ListNode(-1);
		ListNode* p = head;
		int ix = 0;
		int carry = 0;

		while (l1 && l2) {

			ix = l1->val + l2->val + carry;
			carry = ix / 10;
			ix = ix % 10;
			p->next = new ListNode(ix);
			p = p->next;
			l1 = l1->next;
			l2 = l2->next;
		}

		while (l1) {
			ix = l1->val + carry;
			carry = ix / 10;
			ix = ix % 10;
			p->next = new ListNode(ix);
			p = p->next;
			l1 = l1->next;

		}
		while (l2) {
			ix = l2->val + carry;
			carry = ix / 10;
			ix = ix % 10;
			p->next = new ListNode(ix);
			p = p->next;
			l2 = l2->next;

		}

		if (l1 == NULL && l2 == NULL && carry != 0) {

			p->next = new ListNode(carry);
			p = p->next;
		}

		return head->next;
	}
};