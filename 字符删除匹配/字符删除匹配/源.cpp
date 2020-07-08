#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
int main()
{
	string s1;
	string s2;
	cin >> s1 >> s2;
	sort(s1.begin(), s1.end());
	sort(s2.begin(), s2.end());
	string s;
	int i = 0;
	int j = 0;
	for (; i < s1.size(); )
	{
		if (s1[i] == s2[j])
		{
			i++;
			j++;
		}
		else
		{
			s += s1[i];
			i++;
		}
	}
	cout << s << endl;
	system("pause");
	return 0;
}