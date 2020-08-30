
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


/*给出两个?非空 的链表用来表示两个非负的整数。其中，它们各自的位数是按照逆序的方式存储的，并且它们的每个节点只能存储一位数字。

如果，我们将这两个数相加起来，则会返回一个新的链表来表示它们的和。

您可以假设除了数字 0 之外，这两个数都不会以 0?开头。

示例：

输入：(2 -> 4 -> 3) + (5 -> 6 -> 4)
输出：7 -> 0 -> 8
原因：342 + 465 = 807

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