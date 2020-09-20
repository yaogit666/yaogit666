#include<iostream>
#include<string>
#include<vector>
using namespace std;
int main()
{
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		string s;
		cin >> s;
		int count = 0;
		int z = 3;
		int j = 0;
		while (z--)
		{
			for (; j < s.size() - 3; j += 3)
			{
				if (s[j] != s[j + 3])
				{
					count++;
					break;
				}
			}
			j = 3-z;
		}
		if (count > 1)
			cout << "No" << endl;
		else
			cout << "Yes" << endl;
	}
	system("pause");
	return 0;
}