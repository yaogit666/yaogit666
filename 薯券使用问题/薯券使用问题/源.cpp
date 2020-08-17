
#include<iostream>
#include<vector>
#include<string>
using namespace std;
int main()
{
	int n;
	cin >> n;
	string s;
	cin >> s;
	vector<int> v;
	for (int i = 0; i < s.size();)
	{
		int sum = 0;
		while (s[i] != ' ' && s[i] != ',' && s[i] != '[' && s[i] != ']')
		{
			sum = sum * 10 + (s[i] - '0');
			v.push_back(sum);
			i++;
		}
		i++;
	}
	vector<vector<int>> dp (v.size()+1,vector<int>(n+1,0));
	dp[0][0] = 1;
	for (int i = 1; i < v.size()+1; i++)
	{
		for (int j = 0; j < n + 1; j++)
		{
			if (j >= v[i - 1])
				dp[i][j] = dp[i - 1][j] + dp[i][j - v[i - 1]];
			else
				dp[i][j] = dp[i - 1][j];
		}
	}
	cout << dp[v.size()][n] << endl;
	system("pause");
	return 0;
}