#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main()
{
	int n;
	cin >> n;
	vector<int> v;
	for (int i = 0; i < n; i++)
	{
		int x;
		cin >> x;
		v.push_back(x);
	}
	if (n == 1)
		cout << v[0] << ' ' << 1 << endl;
	if (n == 2)
		cout << max(v[0], v[1]) << ' ' << 1 << endl;

	vector<int> dpMaxSum(n, 0);
	vector<int> dpCount(n, 1);
	dpMaxSum[0] = v[0];
	dpMaxSum[1] = max(v[0], v[1]);

	for (int i = 2; i < n; i++)
	{
		dpMaxSum[i] = max(dpMaxSum[i - 1], dpMaxSum[i - 2] + v[i]);

		if (dpMaxSum[i - 1] >= dpMaxSum[i - 2] + v[i])
			dpCount[i] = dpCount[i - 1];
		else
			dpCount[i] = dpCount[i - 2] + 1;
	}
	cout << dpMaxSum[n - 1] << ' ' << dpCount[n - 1] << endl;
	system("pause");
	return 0;
}