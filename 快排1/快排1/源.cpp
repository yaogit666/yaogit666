#include<iostream>
#include<vector>
using namespace std;
void fastSort(vector<int>& v, int left, int right)
{
	int i = left;
	int j = right;
	if (left >= right)
		return;
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
	}
	fastSort(v, i, left-1);
	fastSort(v, left+1, j);
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
	fastSort(v, 0, v.size()-1);
	for (int i = 0; i < v.size(); i++)
	{
		cout << v[i] << ' ';
	}
	cout << endl;
	system("pause");
	return 0;
}