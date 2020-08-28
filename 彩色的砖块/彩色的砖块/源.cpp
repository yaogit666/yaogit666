#include<iostream>
#include<string>
#include<vector>
using namespace std;
int main()
{
	string s;
	cin >> s;
	vector<int> v(26.0);
	for (int i = 0; i < s.size(); i++)
	{
		v[s[i] - 'A']++;
	}
	int count = 0;
	for (int i = 0; i < v.size(); i++)
	{
		if (v[i] != 0)
			count++;
	}
	if (count == 1)
		cout << 1 << endl;
	else if (count == 2)
		cout << 2 << endl;
	else
		cout << 0 << endl;
	return 0;
}