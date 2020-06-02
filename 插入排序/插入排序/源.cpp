#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
void InsertSort(vector<int>& v, int len)
{
	int n = 0;
	for (int i = 1; i < len; i++)
	{
		n = v[i];
		int j = i - 1;
		while(j>=0 && n < v[j])
		{
			v[j+1] = v[j];
			j--;
		}
		v[j+1] = n;
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
	InsertSort(v, len);
	for (int i = 0; i < len; i++)
	{
		cout << v[i] << ' ';
	}
	cout << endl;
	system("pause");
	return 0;
}