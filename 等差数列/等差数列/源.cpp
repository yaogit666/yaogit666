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
		int x;
		cin >> x;
		v[i] = x;
	}
	sort(v.begin(), v.end());
	int key = v[1] - v[0];
	bool b = true;
	for (int i = 1; i < n; i++)
	{
		if (v[i] - v[i - 1] != key)
		{
			b = false;
			break;
		}
	}
	if (b)
		cout << "Possible" << endl;
	else
		cout << "Impossible" << endl;
	return 0;
}