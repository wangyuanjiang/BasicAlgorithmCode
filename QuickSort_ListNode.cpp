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


	//while (right !=pend)  //����д��©�����һ��Ԫ�أ���Ϊһ����˵pend����ĩβ��null����ĩβ��㣬������������
							//���Ҫ����д�Ļ����͵ð�pendֱ������Ϊnull�����ñ���headһ�飻

	while (right != nullptr && right != pend->next)		//����д��Ҫ��head����һ�飬�ҵ�ĩβ���
	{
		if (right->val < tem) {	//���right��ָ��С�ڻ�׼ֵ�����ƶ�left Ȼ�󽻻������right��ָ����ڻ�׼ֵ����ֱ������
			
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
	while (endlist->next != nullptr) { //endlist ��ĩβ��㣬���ǿս��
		
		endlist = endlist->next;
	}

	QuickSort_ListNode(head, endlist);

	return head;
}