#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int secondMax(vector<int>& v)
{
	sort(v.begin(), v.end());
	int lenth = v.size() - 1;
	int secondMaxN;
	int n = 2;
	for (int i = lenth; i >= 0; i--)
	{
		if (v[i] == v[i - 1])
			continue;
		else
		{
			n--;
		}

		if (n == 0)
		{
			secondMaxN = v[i];
			break;
		}
	}
	return secondMaxN;
}
int main()
{
	vector<int> v;
	int n; 
	while (cin >> n)
	{
		v.push_back(n);
		if (cin.get() == '\n')
			break;
	}
	cout << secondMax(v) << endl;
	system("pause");
	return 0;
}