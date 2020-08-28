#include<iostream>
#include<string>
using namespace std;
int main()
{
	string s;
	cin >> s;
	int count = 1;
	int maxC = 0;
	for (int i = 1; i < s.size(); i++)
	{
		if (s[i] != s[i - 1])
			count++;
		else
			count = 1;
		if (maxC < count)
			maxC = count;
	}
	cout << maxC << endl;
	return 0;
}