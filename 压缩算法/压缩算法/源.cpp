#include<iostream>
#include<string>
#include<sstream>
using namespace std;
int main()
{
	string s;
	cin >> s;
	int i = 0;
	while (i < s.size())
	{
		if (s[i] == ']')
		{
			int j = i;
			int k = 0;
			while (s[j] != '[')
			{
				if (s[j] == '|')
				{
					k = j;
				}
				j--;
			}
			stringstream ss;
			ss << s.substr(j + 1, k - j);
			int n;
			ss >> n;
			string str = s.substr(k + 1, i - k - 1);
			string newS;
			for (int c = 0; c < n; c++)
			{
				newS += str;
			}
			s = s.replace(j, i - j + 1, newS);
			i = j - 1;
		}
		i++;
	}
	cout << s << endl;
	return 0;
}