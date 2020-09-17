#include<iostream>
#include<vector>
using namespace std;
int main()
{
	int n, m;
	cin >> n >> m;

	vector<int> v;
	for (int i = 0; i < n; i++)
	{
		int x;
		cin >> x;
		v.push_back(x);
	}
	vector<vector<int>> res;
	for (int i = 0; i < m; i++)
	{
		int x, y;
		cin >> x >> y;
		vector<int> vv;
		vv.push_back(x);
		vv.push_back(y);
		res.push_back(vv);
	}
	for (int z = 0; z < res.size(); z++)
	{
		int count = 0;
		bool b = false;
		for (int i = res[z][0]; i <= res[z][1]; i++)
		{
			for (int j = 0; j < v.size(); j++)
			{
				if (v[j] % i == 0)
					b = true;
			}
			if (b)
			{
				count++;
				b = false;
			}
		}
		cout << count << endl;
	}
	system("pause");
	return 0;
}