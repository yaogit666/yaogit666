#include<iostream>
#include<string>
using namespace std;
int main()
{
	int n;
	string s;
	cin >> n;
	cin >> s;
	int count = 0;
	for (int i = 0; i < n / 2; i++)
	{
		if (s[i] == s[n - i - 1])
			continue;
		else
			count += 1;
	}
	cout << count << endl;
	return 0;
}