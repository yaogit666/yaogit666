#include <iostream>
#include <vector>
#include<string>
using namespace std;

string char_count(string str) {
	int len = str.size() - 1;
	string s = "";
	int count = 1;
	for (int i = 1; i < str.size(); i++)
	{
		if (str[i] == str[i - 1])
		{
			count++;
		}
		else
		{
			s += to_string(count);
			s += str[i - 1];
			count = 1;
		}
	}
	if (str[len] == str[len - 1])
	{
		s += to_string(count);
		s += str[len];
	}
	else
	{
		s += to_string(count);
		s += str[len];
	}
	return s;
}

int main() {
	string res;

	string _str = "";
	cin >> _str;

	res = char_count(_str);
	cout << res << endl;
	system("pause");
	return 0;

}