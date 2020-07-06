#include <iostream>
using namespace std;
int main()
{
	int n, max = 0, sum = 0;
	cin >> n;
	int s;
	for (int i = 0; i < n; i++)
	{
		cin >> s;
		if (s > max)
		{
			sum += max;
			max = s;
		}
		else
		{
			sum += s;
		}
	}
	if (max > sum)
		cout << "No\n";
	else
		cout << "Yes\n";
	return 0;
}
