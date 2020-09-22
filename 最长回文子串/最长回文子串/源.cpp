#include<iostream>
#include<string>
#include<vector>
using namespace std;
int main()
{
	string s;
	cin >> s;
	vector<int> m(128, -1);
	int res = 0;
	int left = -1;
	for (int i = 0; i < s.size(); ++i)
	{
		left = max(left, m[s[i]]);
		m[s[i]] = i;
		res = max(res, i - left);
	}
	for (int i = 0; i < s.size() - res; i++)
	{
		if (s[i] == s[res + i])
		{
			cout << s.substr(i, res) << endl;
			break;
		}
	}
	system("pause");
	return 0;
}