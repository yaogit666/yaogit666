#include<iostream>
#include<vector>
using namespace std;
int main()
{
	int n;
	cin >> n;
	vector<vector<int>> v;
	for (int i = 0; i < n * 2 - 1; i++)
	{
		vector<int> vv;
		for (int j = 0; j < n; j++)
		{
			int x;
			cin >> x;
			vv.push_back(x);
		}
		v.push_back(vv);
	}
	vector<int> hashTable(2000, 0);
	for (int i = 0; i < n * 2 - 1; i++)
	{
		for (int j = 0; j < n; j++)
		{
			hashTable[v[i][j]]++;
		}
	}
	vector<int> res;
	for (int i = 0; i < hashTable.size(); i++)
	{
		if (hashTable[i] % 2 != 0)
			res.push_back(i);
	}
	for (int i = 0; i < res.size() - 1; i++)
	{
		cout << res[i] << ' ';
	}
	cout << res[res.size() - 1] << endl;
	system("pause");
	return 0;
}