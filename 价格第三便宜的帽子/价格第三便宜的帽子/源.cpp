#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main()
{
	int n;
	cin >> n;
	vector<int> v(n, 0);
	while (n--)
	{
		int N;
		cin >> N;
		v.push_back(N);
	}
	sort(v.begin(), v.end());
	int count = 0;
	int key;
	for (int i = 1; i < v.size(); i++)
	{
		if (v[i] != v[i - 1])
			count++;
		if (count == 3)
			key = v[i];
	}
	if (count < 3)
		cout << -1 << endl;
	else
		cout << key << endl;
	return 0;
}