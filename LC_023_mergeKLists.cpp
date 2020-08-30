
#include<iostream>
#include<vector>
#include<algorithm>
#include<map>
using namespace std;
  struct ListNode {
      int val;
     ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
  };
 
class Solution {
public:
	ListNode* mergeKLists(vector<ListNode*>& lists) {
		ListNode *head = new ListNode(0);
		if (!lists.size())
			return head->next;
		size_t k = 0;
		for (size_t i = 0; i < lists.size(); i++) {
			ListNode*L = lists[i];
			if (!L)
				k++;
		}
		if (k == lists.size())
			return head->next;

		vector<int> vec;
		/*ListNode*L = lists[0];
		for (size_t i = 0; i < lists.size();) {
			while (L) {
				vec.push_back(L->val);
				L = L->next;
			}
			if (!L) {
				i++;
				if (i < lists.size())
					L = lists[i];
			}

		}*/

		for (ListNode* L : lists)//±ÈÉÏÃæ¼ò½à
		{
			while (L != NULL) {
				vec.push_back(L->val);
				L = L->next;
			}
		}

		sort(vec.begin(), vec.end());
		//ListNode *head=new ListNode(0);
		ListNode  *ptemp, *pnew;
		ptemp = head;
		for (size_t i = 0; i < vec.size(); i++) {
			pnew = new ListNode(vec[i]);
			ptemp->next = pnew;
			ptemp = ptemp->next;
		}
		return head->next;
	}

};

class Solution {
public:
	ListNode* mergeKLists(vector<ListNode*>& lists) {
		multimap<int, ListNode*> headMap;
		for (ListNode* l : lists)
		{
			if (l != NULL)
				headMap.insert(pair<int, ListNode*>(l->val, l));
		}
		ListNode dummy(0);
		ListNode* tail = &dummy;
		while (!headMap.empty())
		{
			multimap<int, ListNode*>::iterator iterator = headMap.begin();
			tail->next = iterator->second;
			tail = tail->next;
			if (iterator->second->next != NULL) headMap.insert(pair<int, ListNode*>(iterator->second->next->val, iterator->second->next));
			headMap.erase(iterator);
		}
		tail->next = NULL;
		return dummy.next;
	}
};

