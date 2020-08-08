#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<iomanip>
using namespace std;
int main()
{
	string s1;
	string s2;
	cin >> s1 >> s2;
	int len1 = s1.size();
	int len2 = s2.size();
	vector<vector<int>> dp(len1+1, vector<int>(len2+1, 0));
	for (int i = 1; i < len1 + 1; i++)
	{
		for (int j = 1; j < len2 + 1; j++)
		{
			if (s1[i - 1] == s2[j - 1])
			{
				dp[i][j] = dp[i - 1][j - 1] + 1;
			}
			else
			{
				dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
			}
		}
	}
	double n = double(dp[len1][len2]) / double(s1.size());
	cout << setiosflags(ios::fixed) << setprecision(2) << n << ' ';
	if (n >= 5)
		cout << "NO" << endl;
	else
		cout << "YES" << endl;
	system("pause");
	return 0;
}