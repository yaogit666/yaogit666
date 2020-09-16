#include<iostream>
using namespace std;

struct List {
	int val;
	List* next;
	List(int x)
		:val(x)
		, next(NULL)
	{}
};
int main()
{
	int n;
	cin >> n;
	List *newHead = new List(0);
	List *p = newHead;
	int x = 1;
	for (int i = 0; i < n - 1; i++)
	{
		p->next = new List(x);
		p = p->next;
		x++;
	}
	p->next = newHead;
	p = p->next;
	while (p->next != p)
	{
		int i = 2;
		List* pre = p->next;
		while (i--)
		{
			p = p->next;
		}
		List* Next = p->next;
		pre->next = Next;
		p = Next;
	}
	cout << p->val << endl;
	return 0;
}