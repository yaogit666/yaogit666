#include<iostream>
#include<string>
#include<stack>
#include<unordered_map>
using namespace std;
bool Yes(string &s)
{
	string str;
	for (int i = 0; i < s.size(); i++)
	{
		if (s[i] == '{' || s[i] == '}' ||
			s[i] == '[' || s[i] == ']' ||
			s[i] == '(' || s[i] == ')')
		{
			str += s[i];
		}
		else
			continue;
	}
	unordered_map<char, int> m = { {'(',1},{'[',2},{'{',3},{')',4},{']',5},{'}',6} };
	stack<int> table;
	for (auto a : str)
	{
		int n = m[a];
		if (n <= 3)
			table.push(n);
		else if(n>3 && !table.empty())
		{
			int c = table.top();
			if (n-3 != c)
				return false;
			table.pop();
		}
		else
		return false;
			
	}
	if (table.empty())
		return true;
	else
		return false;
}
int main()
{
	string s;
	cin >> s;
	cout << Yes(s) << endl;
	system("pause");
	return 0;
}