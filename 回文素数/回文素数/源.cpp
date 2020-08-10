
#include <iostream>
using namespace std;

int huiwen(int n)   
{
	int x = 0;
	int s = n;
	while (s > 0)
	{
		x = x * 10 + s % 10;
		s = s / 10;
	}
	if (x == n)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

int sushu(int n)   
{
	int x = n;
	int i;
	for (i = 2; i <= n - 1; i++)
	{
		if (x%i == 0)
			return 0;
	}
	return 1;
}

int main()
{
	int n, m;
	cin >> n >> m;
	int ans = 0;
	for (int i = n; i <= m; i++)
	{

		if (huiwen(i) && sushu(i))
		{
			cout << i << " ";
			ans++;
			if (ans % 10 == 0)
				cout << endl;
		}

	}
	system("pause");
	return 0;
}