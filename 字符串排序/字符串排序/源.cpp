#include<iostream>
#include<string>
#include<vector>
using namespace std;
void sort1(vector<string> &v)
{
	for (int i = 0; i < v.size() - 1; i++)
	{
		for (int j = 0; j < v.size() - 1 - i; j++)
		{
			if ((v[j] + v[j + 1]) > (v[j + 1] + v[j]))
			{
				string s = v[j];
				v[j] = v[j + 1];
				v[j + 1] = s;
			}
		}
	}
}
void sort2(vector<string> &v)
{
	for (int i = 0; i < v.size() - 1; i++)
	{
		for (int j = 0; j < v.size() - 1 - i; j++)
		{
			if (v[j].size() > v[j + 1].size())
			{
				string s = v[j];
				v[j] = v[j + 1];
				v[j + 1] = s;
			}
		}
	}
}
int main()
{
	int n;
	cin >> n;
	vector<string> v1;
	vector<string> v2;
	for (int i = 0; i < n; i++)
	{
		string s;
		cin >> s;
		v1.push_back(s);
		v2.push_back(s);
	}
	sort1(v1);
	for (int i = 0; i < n - 1; i++)
	{
		cout << v1[i] << ' ';
	}
	cout << v1[n - 1] << endl;
	sort2(v2);
	for (int i = 0; i < n - 1; i++)
	{
		cout << v2[i] << ' ';
	}
	cout << v2[n - 1] << endl;
	system("pause");
	return 0;
}