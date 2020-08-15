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
	ListNode* removeNthFromEnd(ListNode* head, int n) {
		ListNode* l = new ListNode(-1);
		l->next = head;
		ListNode* fast = l;
		ListNode* slow = l;
		int i = 0;
		while (fast->next != NULL)
		{
			if (i < n)
			{
				fast = fast->next;
				i++;
			}
			else
			{
				fast = fast->next;
				slow = slow->next;
			}
		}
		slow->next = slow->next->next;
		return l->next;
	}
};