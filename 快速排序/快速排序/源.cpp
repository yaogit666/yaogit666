#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

void QuickSort(vector<int> &v, int left, int right)
{
	int i = left;
	int j = right;
	if (left >= right)
	{
		return;
	}
	while (left < right)
	{
		int key = v[left];
		while (left < right && key <= v[right])
		{
			right--;
		}
		if (key > v[right])
		{
			swap(v[left], v[right]);
			left++;
		}
		while (left < right && key >= v[left])
		{
			left++;
		}
		if (key < v[left])
		{
			swap(v[left], v[right]);
			right--;
		}
		QuickSort(v, i,left - 1);
		QuickSort(v, left + 1, j);
	}
}

int main()
{
	vector<int> v;
	int n = 0;
	while (cin >> n)
	{
		v.push_back(n);
		if (cin.get() == '\n')
			break;
	}
	int left = 0;
	int right = v.size() - 1;
	QuickSort(v, left, right);
	for (int i = 0; i < v.size(); i++)
	{
		cout << v[i];
	}
	system("pause");
	return 0;

}