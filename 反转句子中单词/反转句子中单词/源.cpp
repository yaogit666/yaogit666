#include<iostream>
#include<string>
#include<stack>
using namespace std;
int main()
{
	string s;
	getline(cin, s);
	stack<string> table;
	int j = 0;
	for (int i = 0; i < s.size(); i++)
	{
		if (s[i] == ' ')
		{
			table.push(s.substr(j, i - j));
			j = i + 1;
		}
	}
	table.push(s.substr(j, s.size() - j));
	string newS;
	while (!table.empty())
	{
		newS += table.top();
		table.pop();
		if (!table.empty())
			newS += " ";
	}
	cout << newS << endl;
	system("pause");
	return 0;
}