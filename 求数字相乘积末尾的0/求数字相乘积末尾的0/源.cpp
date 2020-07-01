#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main()
{
	vector<int> v;
		v.push_back(100);
		v.push_back(100000);
		v.push_back(4000000);
	int a = 0;
	int b = 0;
	for (int i = 0; i < 3; i++)
	{
		while (v[i]%2 == 0)
		{
			v[i] /= 2;
			a++;
		}
		while (v[i] % 5 == 0)
		{
			v[i] /= 5;
			b++;
		}
	}
	cout << min(a, b) << endl;
	system("pause");
	return 0;
}