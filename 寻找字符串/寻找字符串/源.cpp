#include<iostream>
#include<string>
using namespace std;
int Strcmp(string& s1, string& s2)
{
	for (int i = 0; i < s1.size(); i++)
	{
		if (s1[i] != s2[i])
		{
			return 1;
		}
	}
	return 0;
}
int main()
{
	string s;
	string str;
	getline(cin, s);
	cin >> str;
	int count = 0;
	int lenth = str.size();
	for (int i = 0; i <= s.size() - lenth; i++)
	{
		string ss = s.substr(i, lenth);
		int n = Strcmp(ss, str);
		if (n == 0)
			count += 1;
	}
	cout << count << endl;
	return 0;
}