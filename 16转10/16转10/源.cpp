
#include<iostream>
#include<string>
using namespace std;
int main() {
	string s;
	while (cin >> s) {
		int length = s.size();
		if (length <= 2)
			continue;
		if (s[0] != '0' || s[1] != 'x')
			continue;

		int res = 0;
		int flag = 1;
		for (int i = length - 1; i > 1; --i) {
			char cur = s[i];
			if (cur >= 'A'&&cur <= 'F') {
				res += (cur - 'A' + 10)*flag;
			}
			else if (cur >= '0' && cur <= '9') {
				res += (cur - '0')*flag;
			}
			else
				continue;
			flag *= 16;
		}
		cout << res << endl;
	}
	return 0;
}