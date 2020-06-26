#include<map>
#include<vector>
#include<algorithm>
#include<iostream>
using namespace std;
int main()
{
	int n;
	cin >> n;
	vector<int> v;
	map<int, int> m;
	for (int i = 0; i < n; i++)
	{
		int tep;
		cin >> tep;
		v.push_back(tep);
		m[tep] = i;
	}
	int count = 0;
	sort(v.begin(), v.end());
	for (int i = 0; i < n-1; i++)
	{
		int pos = n;
		if (m[v[i]] > m[v[i + 1]])
		{
			m[v[i+1]] = pos++;
			count++;
		}
	}
	cout << count << endl;
	system("pause");
	return 0;
}








