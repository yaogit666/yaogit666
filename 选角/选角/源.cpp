#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main()
{
	int n;
	cin >> n;
	while (n--)
	{
		int n1;
		int n2;
		cin >> n1 >> n2;
		vector<int> v1;
		vector<int> v2;
		for (int i = 0; i < n1; i++)
		{
			int x;
			cin >> x;
			v1.push_back(x);
		}
		for (int i = 0; i < n2; i++)
		{
			int x;
			cin >> x;
			v2.push_back(x);
		}
		vector<int> v;
		sort(v1.begin(), v1.end());
		sort(v2.begin(), v2.end());
		int key = 0;
		int j = 0;
		for (int i = 0; i < n1; i++)
		{
			for (int j = 0; j < n2; j++)
			{
				if (v2[j] >= v1[i])
				{
					v.push_back(j + 1);
					break;
				}
				else if (j == n2 - 1)
				{
					v.push_back(-1);
					break;
				}
			}
		}
		int len = v.size();
		for (int i = 0; i < len - 1; i++)
		{
			cout << v[i] << ' ';
		}
		cout << v[len - 1] << endl;
	}
	system("pause");
	return 0;
}