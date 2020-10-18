#include<iostream>
#include<string>
#include<stack>
using namespace std;
string removeKdigits(string num, int k) {
	string s;
	if (num.empty())
		return s;
	if (num.size() == k)
	{
		s = '0';
		return s;
	}
	stack<char> table;
	table.push(num[0]);
	int i = 1;
	while (k > 0 || i < num.size())
	{

		if ((table.top() - '0' >= num[i] - '0') && k > 0)
		{
			table.pop();
			table.push(num[i]);
			k--;
		}

		else
		{
			table.push(num[i]);
		}
		i++;
	}
	string ss;
	while (!table.empty())
	{
		char c = table.top();
		ss += c;
		table.pop();
	}
	bool b = false;
	for (int i = ss.size() - 1; i >= 0; i--)
	{
		if (ss[i] == '0' && !b)
			continue;
		else
		{
			s += ss[i];
			b = true;
		}
	}
	if (s.empty() && !ss.empty())
		s = '0';
	return s;
}

	int main()
	{
		string num;
		cin >> num;
		int k;
		cin >> k;
		string s = removeKdigits(num, k);
		cout << s << endl;
		system("pause");
		return 0;
	}