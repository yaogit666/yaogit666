class Solution {
public:
	string reverseLeftWords(string s, int n) {
		string s1 = s.substr(0, n);
		string s2 = s.substr(n);
		return s2 + s1;
	}
};