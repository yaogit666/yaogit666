#include <unordered_map>
class Solution {
public:
	/**
	 *
	 * @param numbers int����vector
	 * @param target int����
	 * @return int����vector
	 */
	vector<int> twoSum(vector<int>& numbers, int target) {
		unordered_map<int, int> m;
		for (int i = 0; i < numbers.size(); i++)
		{
			int b = target - numbers[i];
			if (m.find(b) != m.end())
			{
				return vector<int> {m[b] + 1, i + 1};
			}
			m[numbers[i]] = i;
		}
		return vector<int>{};
	}
};