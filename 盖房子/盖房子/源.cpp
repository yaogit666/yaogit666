
class Solution {
public:
	int getHouses(int t, int* xa, int xaLen) {
		int ret = 2;
		vector<int> x, a;
		for (int i = 0; i < xaLen; i += 2) {
			x.emplace_back(xa[i]);
			a.emplace_back(xa[i + 1]);
		}
		int n = x.size();
		if (n == 1) return 2;
		for (int i = 0; i < n - 1; i++) {
			double lo = (double)x[i] + (double)a[i] / 2.0;
			double hi = (double)x[i + 1] - (double)a[i + 1] / 2.0;
			if (hi - lo < t) continue;
			if (hi - lo == t) {
				ret++;
			}
			else {
				ret += 2;
			}
		}
		return ret;
	}
};