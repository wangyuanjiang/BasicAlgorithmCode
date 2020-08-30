#include <iostream>
#include<string>
#include<vector>
#include<cstdlib>
#include<ctime>

using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL){}
	
} *LinkList;

// https://blog.csdn.net/Neo_dot/article/details/81046141

ListNode *Partition(ListNode *pstart, ListNode *pend)
{
	ListNode *left = pstart;
	ListNode *right = pstart->next;
	int tem = pstart->val;


	//while (right !=pend)  //这样写会漏掉最后一个元素，因为一般来说pend不是末尾的null而是末尾结点，它还包含数据
							//如果要这样写的话，就得把pend直接设置为null，不用遍历head一遍；

	while (right != nullptr && right != pend->next)		//这样写需要把head遍历一遍，找到末尾结点
	{
		if (right->val < tem) {	//如果right的指向小于基准值，则移动left 然后交换，如果right的指向大于基准值，则直接跳过
			
			left = left->next;
			if (left != right)
				swap(left->val, right->val);

		}
		right = right->next;
	}
	swap(left->val, pstart->val);
	return left;
}

void QuickSort_ListNode(ListNode *pstart, ListNode *pend) {

	if (pstart == pend || pstart == nullptr)
		return;

	    ListNode *tem = Partition(pstart, pend);
		QuickSort_ListNode(pstart, tem);
		QuickSort_ListNode(tem->next, pend);
	
}

ListNode * ListNodeSort_By_QuickSort(ListNode *head)
{
	if (head == nullptr)
		return head;
	ListNode *endlist = head;
	while (endlist->next != nullptr) { //endlist 是末尾结点，不是空结点
		
		endlist = endlist->next;
	}

	QuickSort_ListNode(head, endlist);

	return head;
}