#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main()
{
	int n;
	cin >> n;
	vector<int> v(n, 0);
	for (int i = 0; i < n; i++)
	{
		int x = 0;
		cin >> x;
		v[i] = x;
	}
	sort(v.begin(), v.end());
	int count = 2;
	for (int i = 1; i < n; i++)
	{
		if (v[i - 1] != v[i])
		{
			count--;
		}
		if (count == 0)
		{
			cout << v[i] << endl;
			break;
		}
	}
	if (count != 0)
		cout << -1 << endl;
	return 0;
}