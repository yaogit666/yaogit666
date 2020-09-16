#include<iostream>
#include<vector>
using namespace std;
int main()
{
	int n;
	while (cin >> n)
	{
		vector<int>v(n, 0);
		for (int i = 0; i < n; i++)
		{
			int x;
			cin >> x;
			v[i] = x;
		}
		int count = 0;
		for (int i = 0; i < n; i++)
		{
			count += v[i] / 100;
			v[i] = v[i] % 100;
			if (v[i] == 0)
				continue;
			count += v[i] / 50;
			v[i] = v[i] % 50;
			if (v[i] == 0)
				continue;
			count += v[i] / 20;
			v[i] = v[i] % 20;
			if (v[i] == 0)
				continue;
			count += v[i] / 10;
			v[i] = v[i] % 10;
			if (v[i] == 0)
				continue;
			count += v[i] / 5;
			v[i] = v[i] % 5;
			if (v[i] == 0)
				continue;
			count += v[i] / 2;
			v[i] = v[i] % 2;
			if (v[i] == 0)
				continue;
			count += v[i] / 1;
			v[i] = v[i] % 1;
			if (v[i] == 0)
				continue;
		}
		cout << count << endl;
	}
	system("pause");
	return 0;
}