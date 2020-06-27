#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main()
{
	int n;
	vector<int>v;
	cin >> n;
	while (n--)
	{
		int tep;
		cin >> tep;
		v.push_back(tep);
	}
	int maxN = 0;
	for (int i = 0; i <= v.size() - 3; i++)
	{
		maxN = max(abs(v[i + 2] - v[i + 1]) + abs(v[i + 1] - v[i]) - abs(v[i + 2] - v[i]), maxN);
	}
	int count = 0;
	for (int i = 0; i < v.size() - 1; i++)
	{
		count += abs(v[i + 1] - v[i]);
	}
	cout << count - maxN << endl;
	return 0;
}