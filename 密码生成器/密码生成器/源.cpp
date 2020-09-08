#include<iostream>
#include<string>
using namespace std;
int main()
{
	string s;
	getline(cin, s);
	int j = 0;
	for (int i = 0; i < s.size(); i++)
	{
		if (s[i] == ' ')
		{
			string ss = s.substr(j, i - j);
			j = i + 1;
			bool b1 = false;
			bool b2 = false;
			bool b3 = false;
			bool b4 = false;
			for (int j = 0; j < ss.size(); j++)
			{
				if (ss[j] >= '0' && ss[j] <= '9')
					b1 = true;
				else if (ss[j] >= 'a' && ss[j] <= 'z')
					b2 = true;
				else if (ss[j] >= 'A' && ss[j] <= 'Z')
					b3 = true;
				else
					b4 = true;
			}
			if (ss.size() < 8 || ss.size() > 120)
			{
				cout << '1' << endl;
			}
			else if (!(b1&&b2&&b3&&b4))
			{
				cout << '2' << endl;
			}
			else
				cout << '0' << endl;
		}
	}
	string ss = s.substr(j, s.size() - j);
	bool b1 = false;
	bool b2 = false;
	bool b3 = false;
	bool b4 = false;
	for (int j = 0; j < ss.size(); j++)
	{
		if (ss[j] >= '0' && ss[j] <= '9')
			b1 = true;
		else if (ss[j] >= 'a' && ss[j] <= 'z')
			b2 = true;
		else if (ss[j] >= 'A' && ss[j] <= 'Z')
			b3 = true;
		else
			b4 = true;
	}
	if (ss.size() < 8 || ss.size() > 120)
		cout << '1' << endl;
	else if (!(b1&&b2&&b3&&b4))
		cout << '2' << endl;
	else
		cout << '0' << endl;
	system("pause");
	return 0;
}