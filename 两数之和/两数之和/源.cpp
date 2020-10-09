#include <unordered_map>
class Solution {
public:
	/**
	 *
	 * @param numbers int整型vector
	 * @param target int整型
	 * @return int整型vector
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