#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;
int main()
{
	string s;
	cin >> s;
	int len = s.size();
	if (len == 1)
	{
		cout << s << endl;
		system("pause");
		return 0;
	}
	if (len == 2)
	{
		if (s[0] == s[1])
			cout << s << endl;
		else
		{
			s += s[0];
			cout << s << endl;
		}
		system("pause");
		return 0;
	}
	vector<vector<int>> dp(len, vector<int>(len, 0));
	for (int i = 0; i < len - 1; i++)
	{
		if (s[i] != s[i + 1])
			dp[i][i + 1] = 1;
	}
	for (int i = len - 3; i >= 0; i--)
	{
		for (int j = i + 2; j < len; j++)
		{
			if (s[i] == s[j])
				dp[i][j] = dp[i + 1][j - 1];
			else
				dp[i][j] = min(dp[i + 1][j], dp[i][j - 1]) + 1;
		}
	}
	int newL = len + dp[0][len - 1];
	string str(newL, '\0');
	int l = 0;
	int r = newL-1;
	int i = 0;
	int j = len - 1;
	while (i <= j)
	{
		if (s[i] == s[j])
		{
			str[l++] = s[i++];
			str[r--] = s[j--];
		}
		else if (dp[i][j - 1] < dp[i + 1][j])
		{
			str[l++] = str[r--] = s[j--];
		}
		else
		{
			str[l++] = str[r--] = s[i++];
		}
	}
	cout << str << endl;
	system("pause");
	return 0;
}