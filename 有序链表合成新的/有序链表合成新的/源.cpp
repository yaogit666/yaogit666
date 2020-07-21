class Solution {
public:
	ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
		if (l1 == NULL)
			return  l2;
		if (l2 == NULL)
			return l1;
		ListNode* newHead = new ListNode(-1);
		ListNode* l = newHead;
		if (l1 == NULL && l2 == NULL)
			return newHead;
		while (l1 != NULL && l2 != NULL)
		{
			if (l1->val < l2->val)
			{
				l->next = l1;
				l1 = l1->next;
			}
			else
			{
				l->next = l2;
				l2 = l2->next;
			}
			l = l->next;
		}
		if (l1 == NULL)
			l->next = l2;
		else
			l->next = l1;
		return newHead->next;
	}
};