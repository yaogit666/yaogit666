#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
void BubbleSort(vector<int> &v, int s)
{
	for (int i = 0; i < s-1; i++)
	{
		for (int j = 0; j < s-i-1; j++)
		{
			if (v[j] > v[j+1])
				swap(v[j], v[j+1]);
		}
	}
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
	int len = v.size();
	BubbleSort(v, len);
	for (int i = 0; i < len; i++)
	{
		cout << v[i] << ' ';
	}
	cout << endl;
	system("pause");
	return 0;
}