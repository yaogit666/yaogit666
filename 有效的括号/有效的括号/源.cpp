class Solution {
public:
	bool isValid(string s) {

		unordered_map<char, int> m = { {'(',1},{'[',2},{'{',3},{')',4},{']',5},{'}',6} };
		stack<int> tab;
		for (char c : s)
		{
			int n = m[c];
			if (n > 0 && n <= 3)
				tab.push(n);
			else if (n > 3 && n <= 6 && !tab.empty())
			{
				int x = tab.top();
				if (n - 3 != x)
					return false;
				tab.pop();
			}
			else
				return false;
		}
		if (tab.empty())
			return true;
		else
			return false;
	}
};