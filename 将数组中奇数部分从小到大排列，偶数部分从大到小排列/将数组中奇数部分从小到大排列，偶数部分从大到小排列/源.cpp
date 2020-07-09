#include<iostream>
#include<vector>
using namespace std;
void sort1(vector<int> & v, int n)
{
	for (int i = 0; i < n-1; i++)
	{
		for (int j = 0; j < n - 1 - i; j++)
		{
			if (v[j] > v[j + 1])
				swap(v[j], v[j + 1]);
		}
	}
}
void sort2(vector<int> & v, int n)
{
	int len = v.size();
	for (int i = n; i < len - 1; i++)
	{
		for (int j = n; j < len - 1 - i + n; j++)
		{
			if (v[j] < v[j + 1])
				swap(v[j], v[j + 1]);
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
	int left = 0;
	int right = v.size() - 1;
	while (left < right)
	{
		if (v[left] % 2 != 0)
			left++;
		if (v[left] % 2 == 0)
		{
			swap(v[left], v[right]);
			right--;
		}
	}
	sort1(v, left);
	sort2(v, left);
	for (int i = 0; i < v.size(); i++)
	{
		cout << v[i];
	}
	cout << endl;
	system("pause");
	return 0;
}