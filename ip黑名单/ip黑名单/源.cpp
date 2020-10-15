#include<iostream>
#include<string>
#include<vector>
using namespace std;
int main()
{
	string s1;
	string s2;
	getline(cin, s1);
	getline(cin, s2);
	vector<string> v1;
	vector<string> v2;
	int x = 0;
	for (int i = 0; i < s1.size(); i++)
	{
		if (s1[i] == ',')
		{
			string s3 = s1.substr(x, i - x);
			x = i + 2;
			v1.push_back(s3);
		}
	}
	string s3 = s1.substr(x, s1.size() - x);
	v1.push_back(s3);

	x = 0;
	for (int i = 0; i < s2.size(); i++)
	{
		if (s2[i] == ',')
		{
			string s4 = s2.substr(x, i - x);
			x = i + 2;
			v2.push_back(s4);
		}
	}
	string s4 = s2.substr(x, s2.size() - x);
	v2.push_back(s4);



	bool b = false;
	for (int i = 0; i < v1.size()-1; i++)
	{
		for (int j = 0; j < v2.size(); j++)
		{
			if (strcmp(v1[i].c_str(), v2[j].c_str()) == 0)
				b = true;
		}
		if (b)
			cout << "true" << ",";
		else
			cout << "false" << ",";

		b = false;
	}
	for (int j = 0; j < v2.size(); j++)
	{
		if (strcmp(v1[v1.size()-1].c_str(), v2[j].c_str()) == 0)
			b = true;
	}
	if (b)
		cout << "true" << endl;
	else
		cout << "false" << endl;
	return 0;
}
