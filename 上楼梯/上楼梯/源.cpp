#include<iostream>
#include<vector>
using namespace std;
int main()
{
	int n;
	cin >> n;
	if (n == 1)
	{
		cout << 1 << endl;
		system("pause");
		return 0;
	}
	if (n == 2)
	{
		cout << 2 << endl;
		system("pause");
		return 0;
	}
	vector<int> v(n + 1, 0);
	v[1] = 1;
	v[2] = 2;
	for (int i = 3; i < v.size(); i++)
	{
		v[i] = v[i - 1] + v[i - 2];
	}
	cout << v[v.size()-1] << endl;
	system("pause");
	return 0;
}