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

//理论上方法1空间复杂度是O(N),方法2的空间复杂度是O(1),但是实际上在测试中他两占用的内存差不多；

class Solution{ //方法1， 利用hashmap，oredered_map<Node*, Node*>, 将配对信息仿真map中；
public:
	Node* copyRandomList(Node* head) {
		
		if (head == nullptr)		return nullptr;
		
		//创建map对象，并将head的结点复制到map中
		unordered_map<Node*, Node*> copyHead;
		Node* pnode = head;
		while (pnode)
		{
			copyHead[pnode] = new Node(pnode->val);	//添加 key-value 对
			pnode = pnode->next;
		}

		pnode = head;
		//向map中的元素添加 next和random指针；
		while (pnode) 
		{
			//copyHead[pnode]->next =pnode->next;
			//copyHead[pnode]->random = pnode->random;	//这样不行

			copyHead[pnode]->next = copyHead[pnode->next];	//map中value的next = key的next；
			copyHead[pnode]->random = copyHead[pnode->random]; ////map中value的random = key的random；
			pnode = pnode->next;

			//key 和vaule 都是Node*；
			//key就是原链表，value是新创建的链表
		}

		return copyHead[head];
	}

};

class Solution {
public:
	Node* copyRandomList(Node* head) {

		if (head == nullptr)
			return nullptr;

		//方法2：时间复杂度O(n),空间复杂度O(1）
		   //以下是至少有一个节点的情况
		   //复制节点
		Node *pNode = head;
		while (pNode != nullptr)
		{
			Node *pNext = pNode->next;
			//创建新节点
			Node *newNode = new Node(pNode->val);
			//newNode->val = pNode->val;
			//插入新节点
			pNode->next = newNode;
			newNode->next = pNext;
			pNode = pNext;
		}

		//复制随机指针
		Node *preNode = head;
		while (preNode != nullptr)
		{
			pNode = preNode->next;
			//添加随即指针
			pNode->random = preNode->random == nullptr ? nullptr : preNode->random->next;
			//更新当前处理的节点
			preNode = pNode->next;
		}

		//拆分成两个链表
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

class Solution {   //将第2种方法写成函数的形式
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

			pnode->next = pCloned;	//调整pnode->next  d的指向；
			//pCloned = pCloned->next;
			pnode = pCloned->next; //相当于移动两步

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
			pnode = pCloned->next;	//每次移动两步；

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