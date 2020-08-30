#include <iostream>
#include<string>
#include<vector>
#include<cstdlib>
#include<ctime>

using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}

};
/*先将链表分成左右两部分，在将左右部分按照大小顺序合并起来*/

//https://blog.csdn.net/Neo_dot/article/details/81046141
ListNode* MergeTwo(ListNode* pleft, ListNode* pright)
{
	if (pleft == nullptr)
		return pright;
	if (pright == nullptr)
		return pleft;
	ListNode *head;
	if (pleft->val < pright->val) {
		head = pleft;
		pleft = pleft->next;
	}
	else {
		head = pright;
		pright = pright->next;
	}
	ListNode *tem = head;
	while (pleft != nullptr && pright !=nullptr)
	{
		if (pleft->val < pright->val) {
			tem->next = pleft;
			pleft = pleft->next;
			tem = tem->next;
		}
		else {
			tem->next = pright;
			pright = pright->next;
			tem = tem->next;
		}
		
	}
	if (pleft == nullptr)
		tem->next = pright;
	if (pright == nullptr)
		tem->next = pleft;

	return head;

}

ListNode* Mergesort(ListNode* pHead)	//包含里划分和合并
{
	if (pHead == nullptr || pHead->next == nullptr)
		return pHead;
	ListNode *pslow = pHead;
	ListNode *pfast = pHead;

	//while (pfast != NULL && (pfast->next != NULL)) // 一般求中间结点的循环条件，
	while (pfast->next != NULL && (pfast->next->next != NULL)) //此题的快慢指针求中间节点
	{
		pslow = pslow->next;
		pfast = pfast->next->next;
	}
	//上面两种循环条件求中间结点的结果略有不同，对于[1,2,3,4,5,6]的链表，第一个循环条件结束后pslow指向4，第二个循环条件
	//结束后pslow指向3；

	ListNode* Left = pHead;			//从中间分成左右两部分
	ListNode* Right = pslow->next;
	pslow->next = nullptr; //记得把pslow->next（左边末尾的next指针） 置为null；

	ListNode* pLeft = Mergesort(Left);		//左边继续递归细分，
	ListNode* pRight = Mergesort(Right);	//右边继续递归细分

	return MergeTwo(pLeft, pRight);  //合并递归细分之后的结果


}