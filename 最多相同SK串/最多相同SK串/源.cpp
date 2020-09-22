#include<iostream>
#include<stack>
#include<string>
using namespace std;
int main()
{
	string s;
	cin >> s;
	stack<char> table;
	int count = -1;
	for (int i = 0; i <= s.size(); i++)
	{
		if (table.empty())
		{
			table.push(s[i]);
			count += 1;
		}
		else
		{
			if (s[i] == table.top())
			{
				table.push(s[i]);
			}
			else
			{
				table.pop();
			}
		}
	}
	cout << count << endl;
	system("pause");
	return 0;
}
