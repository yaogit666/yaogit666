#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main()
{
	int v;
	int n;
	cin >> v >> n;
	vector<int> table;
	for (int i = 0; i < n; i++)
	{
		int x;
		cin >> x;
		table.push_back(x);
	}
	sort(table.begin(), table.end());
	int key = v;
	for (int i = table.size() - 1; i >= 0; i--)
	{
		int c = key;
		key = key - table[i];
		if (key < 0)
		{
			key = c;
		}
	}
	cout << key << endl;
	system("pause");
	return 0;
}