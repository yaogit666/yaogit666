#include<iostream>
#include<vector>
using namespace std;
typedef struct list
{
	int val;
	list* next;
	list(int v)
		:val(v)
		, next(NULL)
	{}
}list;
int main()
{
	int m;
	int n;
	cin >> m;
	while (m--)
	{
		cin >> n;
		vector<int> v;
		list *l = new list(1);
		list *head = l;

		for (int i = 2; i <= n; i++)
		{
			list *ll = new list(i);
			l->next = ll;
			l = l->next;
		}
		l->next = head;

		while (1)
		{
			list *p1 = head;
			list *p2 = head;
			int count = 2;
			while (count--)
			{
				p1 = p2;
				p2 = p2->next;
			}
			v.push_back(p2->val);
			if (p1->next == p2->next)
			{
				break;
			}
			p1->next = p2->next;
			head = p2->next;
		}

		for (int i = 0; i < v.size(); i++)
		{
			cout << v[i] << ' ';
		}
		cout << endl;
	}
	system("pause");
	return 0;
}