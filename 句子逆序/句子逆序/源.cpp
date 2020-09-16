#include<iostream>
#include<string>
#include<vector>
using namespace std;
int main()
{
	string s;
	getline(cin, s);
	vector<string> v;
	int j = 0;
	for (int i = 0; i < s.size(); i++)
	{
		if (s[i] == ' ')
		{
			string ss = s.substr(j, i - j);
			v.push_back(ss);
			j = i + 1;
		}
	}
	string ss = s.substr(j, s.size() - j);
	v.push_back(ss);
	for (int i = v.size()-1; i > 0; i--)
	{
		string sss = v[i];
		cout << sss << ' ';
	}
	string sss = v[0];
	cout << sss << endl;
	system("pause");
	return 0;
}