#include<iostream>
#include<vector>
using namespace std;
int main()
{
	vector<int> v;
	vector<int> table(1000, 0);
	int n;
	bool b = true;
	while (cin >> n)
	{
		v.push_back(n);
		if (cin.get() == '\n')
		{
			break;
		}
	}
	for (int i = 0; i < v.size(); i++)
	{
		table[v[i]] ++;
	}
	for (int i = 0; i < 1000; i++)
	{
		if (table[i] > 1)
			b = false;
	}
	if (b)
		cout << "true" << endl;
	else
		cout << "false" << endl;
	system("pause");
	return 0;
}