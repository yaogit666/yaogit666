#include<iostream>
#include<string>
#include<vector>
#include<sstream>
using namespace std;
vector<int> v;
void stringToNum(string &s, int n, string& str)
{
	if (n > s.size())
		return;
	if (s[n]-'0' >= 0 && s[n]-'0' < 9)
		str += s[n];
	else
	{
		if (!str.empty())
		{
			stringstream ss;
			int n;
			ss << str;
			ss >> n;
			v.push_back(n);
			str = "";
		}
	}
	n += 1;
	stringToNum(s, n, str);
}
int main()
{
	string s;
	cin >> s;
	string str;
	stringToNum(s, 0, str);
	for (int i = 0; i < v.size(); i++)
	{
		cout << v[i] << endl;
	}
	system("pause");
	return 0;
}