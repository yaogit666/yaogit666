#include<iostream>
#include<string>
#include<sstream>
using namespace std;

bool isIpv4(string &IP)
{
	int j = 0;
	for (int i = 0; i < IP.size(); i++)
	{
		if (IP[i] == '.')
		{
			string s = IP.substr(j, i);
			j = i + 1;
			stringstream ss;
			int n = 0;
			ss << s;
			ss >> n;
			if (n <= 0 || n>255)
			{
				return false;
			}
		}
	}
	string s = IP.substr(j);
	stringstream ss;
	int n = 0;
	ss << s;
	ss >> n;
	if (n <= 0 || n>255)
	{
		return false;
	}
	return true;
}
	
int main()
{
	string s;
	cin >> s;
	cout << isIpv4(s) << endl;
	system("pause");
	return 0;
}