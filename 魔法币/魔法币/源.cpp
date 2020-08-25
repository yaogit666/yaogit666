#include<iostream>
using namespace std;
int main()
{
	int n;
	cin >> n;
	string s;
	while (n > 0)
	{
		if (n % 2 == 0)
		{
			n = (n - 2) / 2;
			s = '2' + s;
		}
		else
		{
			n = (n - 1) / 2;
			s = '1' + s;
		}
	}
	cout << s << endl;
	return 0;
}