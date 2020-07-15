#include<iostream>
#include<string>
#include<stack>
using namespace std;
string reverseWords(string s) {
	string str;
	if (s.empty())
		return str;
	string ss;
	int x = 0;
	int y = s.size() - 1;
	for (; x < s.size(); ++x)
	{
		if (s[x] != ' ')
		{
			break;
		}
	}
	for (; y >= 0; --y)
	{
		if (s[y] != ' ')
		{
			break;
		}
	}
	ss = s.substr(x, y - x + 1);
	if (ss.empty())
		return str;
	stack<string> table;
	string s1;
	int j = 0;
	for (int i = 0; i < ss.size(); i++)
	{
		if (ss[i] == ' ')
		{
			s1 = ss.substr(j, i - j);
			j = i + 1;
			table.push(s1);
			s1.clear();
		}
		while (ss[j] == ' ')
		{
			j++;
			i++;
		}
	}
	if (ss[ss.size() - 1] != ' ')
		table.push(ss.substr(j, ss.size() - j));
	int len = table.size();
	for (int i = 0; i < len - 1; i++)
	{
		string s2 = table.top();
		str += s2;
		str += ' ';
		table.pop();
	}
	str += table.top();
	return str;
}
	int main()
	{
		string s;
		getline(cin, s);
		cout << reverseWords(s);
		system("pause");
		return 0;
	}