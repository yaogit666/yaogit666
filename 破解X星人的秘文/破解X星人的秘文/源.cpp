#include<iostream>
#include<string>
using namespace std;
string mySort(string &s)
{
	string newS;
	for (int i = s.size() - 1; i >= 0; i--)
	{
		newS += s[i];
	}
	return newS;
}
int main()
{
	int n;
	cin >> n;
	string s;
	string ss;
	getline(cin, ss);
	getline(cin, s);
	string newS;
	int j = 0;
	if (s.size() < n)
	{
		newS = mySort(s);
	}
	else
	{
		int i = n;
		for (i; i < s.size(); i += n)
		{
			string str = s.substr(j, i - j);
			newS += mySort(str);
			j = i;
		}
		if (i-n < s.size())
		{
			string str = s.substr(j, s.size() - j);
			newS += mySort(str);
		}
	}
	cout << newS << endl;
	system("pause");
	return 0;
}