#include<iostream>
#include<string>
#include<sstream>
using namespace std;
int main()
{
	string s;
	cin >> s;
	string str;
	for (int i = 0; i < s.size(); i++)
	{
		if (s[i] >= '0' && s[i] <= '9')
			str += s[i];
	}
	int n;
	stringstream ss;
	ss << str;
	ss >> n;
	cout << n << endl;
	system("pause");
	return 0;
}