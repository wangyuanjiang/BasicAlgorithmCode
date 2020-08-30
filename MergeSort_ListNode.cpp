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
/*�Ƚ�����ֳ����������֣��ڽ����Ҳ��ְ��մ�С˳��ϲ�����*/

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

ListNode* Mergesort(ListNode* pHead)	//�����ﻮ�ֺͺϲ�
{
	if (pHead == nullptr || pHead->next == nullptr)
		return pHead;
	ListNode *pslow = pHead;
	ListNode *pfast = pHead;

	//while (pfast != NULL && (pfast->next != NULL)) // һ�����м����ѭ��������
	while (pfast->next != NULL && (pfast->next->next != NULL)) //����Ŀ���ָ�����м�ڵ�
	{
		pslow = pslow->next;
		pfast = pfast->next->next;
	}
	//��������ѭ���������м���Ľ�����в�ͬ������[1,2,3,4,5,6]��������һ��ѭ������������pslowָ��4���ڶ���ѭ������
	//������pslowָ��3��

	ListNode* Left = pHead;			//���м�ֳ�����������
	ListNode* Right = pslow->next;
	pslow->next = nullptr; //�ǵð�pslow->next�����ĩβ��nextָ�룩 ��Ϊnull��

	ListNode* pLeft = Mergesort(Left);		//��߼����ݹ�ϸ�֣�
	ListNode* pRight = Mergesort(Right);	//�ұ߼����ݹ�ϸ��

	return MergeTwo(pLeft, pRight);  //�ϲ��ݹ�ϸ��֮��Ľ��


}