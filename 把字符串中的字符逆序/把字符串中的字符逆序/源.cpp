#include<iostream>
#include<string>
using namespace std;
string back(string &s)
{
	string newS;
	for (int i = s.size() - 1; i >= 0; i--)
	{
		newS += s[i];
	}
	return newS;
}
int main()
{
	string s;
	getline(cin, s);
	string newS = back(s);
	cout << newS << endl;
	system("pause");
	return 0;
}