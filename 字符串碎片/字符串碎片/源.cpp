#include<iostream>
#include<string>
#include <iomanip>
using namespace std;
int main()
{
	string s;
	cin >> s;
	float count = 1;
	for (int i = 1; i < s.size(); i++)
	{
		if (s[i] != s[i - 1])
			count += 1;
	}
	float f = (float)s.size() / count;
	cout << fixed << setprecision(2) << f << endl;
	return 0;
}