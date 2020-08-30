#include "JZOff.h"
class Node {
public:
	int val;
	Node* next;
	Node* random;

	Node(int _val) {
		val = _val;
		next = NULL;
		random = NULL;
	}
};

//�����Ϸ���1�ռ临�Ӷ���O(N),����2�Ŀռ临�Ӷ���O(1),����ʵ�����ڲ���������ռ�õ��ڴ��ࣻ

class Solution{ //����1�� ����hashmap��oredered_map<Node*, Node*>, �������Ϣ����map�У�
public:
	Node* copyRandomList(Node* head) {
		
		if (head == nullptr)		return nullptr;
		
		//����map���󣬲���head�Ľ�㸴�Ƶ�map��
		unordered_map<Node*, Node*> copyHead;
		Node* pnode = head;
		while (pnode)
		{
			copyHead[pnode] = new Node(pnode->val);	//��� key-value ��
			pnode = pnode->next;
		}

		pnode = head;
		//��map�е�Ԫ����� next��randomָ�룻
		while (pnode) 
		{
			//copyHead[pnode]->next =pnode->next;
			//copyHead[pnode]->random = pnode->random;	//��������

			copyHead[pnode]->next = copyHead[pnode->next];	//map��value��next = key��next��
			copyHead[pnode]->random = copyHead[pnode->random]; ////map��value��random = key��random��
			pnode = pnode->next;

			//key ��vaule ����Node*��
			//key����ԭ����value���´���������
		}

		return copyHead[head];
	}

};

class Solution {
public:
	Node* copyRandomList(Node* head) {

		if (head == nullptr)
			return nullptr;

		//����2��ʱ�临�Ӷ�O(n),�ռ临�Ӷ�O(1��
		   //������������һ���ڵ�����
		   //���ƽڵ�
		Node *pNode = head;
		while (pNode != nullptr)
		{
			Node *pNext = pNode->next;
			//�����½ڵ�
			Node *newNode = new Node(pNode->val);
			//newNode->val = pNode->val;
			//�����½ڵ�
			pNode->next = newNode;
			newNode->next = pNext;
			pNode = pNext;
		}

		//�������ָ��
		Node *preNode = head;
		while (preNode != nullptr)
		{
			pNode = preNode->next;
			//����漴ָ��
			pNode->random = preNode->random == nullptr ? nullptr : preNode->random->next;
			//���µ�ǰ����Ľڵ�
			preNode = pNode->next;
		}

		//��ֳ���������
		preNode = head;
		Node *newHead = preNode->next;
		while (preNode != nullptr)
		{
			pNode = preNode->next;

			preNode->next = pNode->next;
			preNode = preNode->next;

			pNode->next = preNode == nullptr ? nullptr : preNode->next;
		}
		return newHead;

	}
};

class Solution {   //����2�ַ���д�ɺ�������ʽ
public:

	Node* copyRandomList(Node* head)
	{
		cloneNode(head);
		connectRandom(head);
		return ReconnectNode(head);

	}
	void cloneNode(Node* head) {

		Node* pnode = head;
		while (pnode)
		{
			Node* pCloned = new Node(pnode->val);
			pCloned->next = pnode->next;
			pCloned->random = NULL;

			pnode->next = pCloned;	//����pnode->next  d��ָ��
			//pCloned = pCloned->next;
			pnode = pCloned->next; //�൱���ƶ�����

		}

	}

	void connectRandom(Node* head) {

		Node* pnode = head;

		while (pnode)
		{
			Node* pCloned = pnode->next;
			if (pnode->random)
			{
				pCloned->random = pnode->random->next;

			}
			pnode = pCloned->next;	//ÿ���ƶ�������

		}
	}

	Node* ReconnectNode(Node* head)
	{
		Node* pnode = head;
		Node* pClonedHead = NULL;
		Node* pClonedNode = NULL;

		if (pnode) {

			pClonedHead = pnode->next;
			pClonedNode = pClonedHead;

			pnode->next = pClonedNode->next;
			pnode = pnode->next;
		}

		while (pnode)
		{
			pClonedNode->next = pnode->next;
			pClonedNode = pClonedNode->next;

			pnode->next = pClonedNode->next;
			pnode = pnode->next;
		}

		return pClonedHead;

	}
};