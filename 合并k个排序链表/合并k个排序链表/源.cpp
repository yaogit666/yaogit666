/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
	ListNode* mergeKLists(vector<ListNode*>& lists) {
		if (lists.size() == 0)
			return nullptr;
		ListNode* L = lists[0];
		for (int i = 1; i < lists.size(); i++)
		{
			L = merge(L, lists[i]);
		}
		return L;
	}

	ListNode* merge(ListNode* L1, ListNode* L2)
	{
		if (!L1) return L2;
		if (!L2) return L1;
		ListNode* head = new ListNode(-1);
		ListNode* L = head;
		while (L1 && L2)
		{
			if (L1->val < L2->val)
			{
				L->next = L1;
				L = L->next;
				L1 = L1->next;
			}
			else
			{
				L->next = L2;
				L = L->next;
				L2 = L2->next;
			}
		}
		if (!L1)
			L->next = L2;
		else
			L->next = L1;
		return head->next;
	}
};