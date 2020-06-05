#include <iostream>
#include<string>
using namespace std;

bool is_valid_ip(const string& ip) {
	int size = 0;
	int n1 = 0;
	for (int i = 0; i < ip.size(); i++) 
	{
		if (ip[i] >= '0' && ip[i] <= '9') 
		{
			n1 = n1 * 10 + (ip[i] - '0');
		}
		else if (ip[i] == '.') 
		{
			if (n1 <= 255 && n1 >= 0) 
			{
				size++;
			}
			else 
			{
				return false;
			}
			n1 = 0;
		}
		else 
		{
			return false;
		}
	}
	if (n1 <= 255 && n1 >= 0) 
	{
		size++;
	}
	if (size == 4) 
	{
		return true;
	}
	else 
	{
		return false;
	}
}

int main() 
{
	string ip;
	cin >> ip;
	cout << (is_valid_ip(ip) ? "Yes" : "No") << endl;
	system("pause");
	return 0;
}