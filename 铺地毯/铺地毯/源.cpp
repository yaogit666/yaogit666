#include<iostream>
#include<vector>
using namespace std;
int main()
{
	int n;
	cin >> n;
	while (n--)
	{
		int len;
		cin >> len;
		int count;
		cin >> count;
		vector<vector<int>> v;
		for (int i = 0; i < count; i++)
		{
			vector<int> vv(2, 0);
			int l, r;
			cin >> l >> r;
			vv[0] = l;
			vv[1] = r;
			v.push_back(vv);
		}
		vector<int> arr(len + 1, 0);
		for (int i = 0; i < count; i++)
		{
			for (int j = v[i][0]; j <= v[i][1]; j++)
				arr[j] += 1;
		}
		for (int i = 1; i < len; i++)
		{
			cout << arr[i] << ' ';
		}
		cout << arr[len] << endl;
	}
	system("pause");
	return 0;
}