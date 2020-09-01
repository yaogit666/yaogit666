#include<iostream>
#include<string>
using namespace std;
string tenToTwo(int n)
{
	string s;
	while (n)
	{
		string str = to_string(n % 2);
		s += str;
		n = n / 2;
	}
	string newS;
	for (int i = s.size() - 1; i >= 0; i--)
	{
		newS += s[i];
	}
	return newS;
}
int main()
{
	int n;
	cin >> n;
	string newS = tenToTwo(n);
	cout << newS << endl;
	system("pause");
	return 0;
}