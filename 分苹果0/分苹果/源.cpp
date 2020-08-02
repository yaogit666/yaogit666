#include<iostream>
#include<iostream>
#include<vector>
using namespace std;
int main()
{
	int n;
	cin >> n;
	vector<int> v(n, 0);
	int sum = 0;
	int x;
	for (int i = 0; i < n; i++)
	{
		cin >> x;
		v[i] = x;
		sum += x;
	}
	if (sum % n != 0)
	{
		cout << -1 << endl;
	}
	else
	{
		int key = sum / n;
		int count = 0;
		for (int i = 0; i < v.size(); i++)
		{
			count += abs((key - v[i])) / 2;
		}
		cout << count / 2 << endl;
	}
	system("pause");
	return 0;
}