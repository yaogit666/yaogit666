#include<iostream>
#include<string>
#include<sstream>
using namespace std;
int main()
{
	string s1;
	cin >> s1;
	string s2;
	for (int i = s1.size() - 1; i >= 0; i--)
	{
		s2 += s1[i];
	}
	stringstream ss1;
	stringstream ss2;
	int n1;
	int n2;
	ss1 << s1;
	ss2 << s2;
	ss1 >> n1;
	ss2 >> n2;
	cout << n1 + n2 << endl;
	return 0;
}