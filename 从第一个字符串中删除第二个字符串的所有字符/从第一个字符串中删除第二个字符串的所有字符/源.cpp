#include<iostream>
#include<string>
#include<vector>
using namespace std;
//Thy r stdnts

void deleteChar(string &s1,string &s2)
{
	string s = "";
	vector<int> hashTable(256, 0);
	for (int i = 0; i < s2.size(); i++)
	{
		hashTable[s2[i]] = 1;
	}
	int slow = 0;
	int fast = 0;
	int len = s1.size();
	while (fast < len )
	{
		if (!hashTable[s1[fast]])
		{
			s1[slow] = s1[fast];
			slow++;
		}
		fast++;
	}
	s1.resize(slow);
}
int main()
{
	string s1 = "They are students";
	string s2 = "aeiou";
	deleteChar(s1, s2);
	cout << s1 << endl;
	system("pause");
	return 0;
}