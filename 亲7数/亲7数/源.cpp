#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<sstream>
using namespace std;

vector<string> res;

vector<int> pro_seven(vector<string>& res)
{
	vector<int> proSevenV;
	for (int i = 0; i < res.size(); i++)
	{
		stringstream s;
		s << res[i];
		int n;
		s >> n;
		if (n % 7 == 0)
			proSevenV.push_back(n);
	}
	return proSevenV;
}
void arrange(string& S, string& s, vector<int>& v)
{
	if (s.size() == S.size())
		res.push_back(s);
	for (int i = 0; i < S.size(); i++)
	{
		if (v[i] == 0)
		{
			if (i > 0 && S[i] == S[i - 1] && v[i - 1] == 1)
			{
				continue;
			}
			s += S[i];
			v[i] = 1;
			arrange(S, s, v);
			s.pop_back();
			v[i] = 0;
		}
	}
}

int main()
{
	string S;
	cin >> S;
	string s;
	vector<int> v(S.size(), 0);
	sort(S.begin(), S.end());
	arrange(S, s, v);
	vector<int> proSevenV = pro_seven(res);
	for (int i = 0; i < proSevenV.size(); i++)
	{
		cout << proSevenV[i] << endl;
	}
	system("pause");
	return 0;
}