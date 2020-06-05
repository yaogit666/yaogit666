class Solution {
public:
	int firstMissingPositive(vector<int>& nums) {
		int len = nums.size();
		if (len == 0)
			return 1;
		sort(nums.begin(), nums.end());
		if (nums[len - 1] <= 0)
			return 1;
		vector<int> v;
		for (int i = 1; i < len; i++)
		{
			if (nums[i] != nums[i - 1])
				v.push_back(nums[i - 1]);
			else
				continue;
		}
		v.push_back(nums[len - 1]);
		int n = 1;
		bool b = false;
		for (int i = 0; i < v.size(); i++)
		{
			if (v[i] <= 0)
				continue;
			if (v[i] == n)
				n++;
			else
			{
				b = true;
				break;
			}
		}
		if (b && n == 1)
			return 1;
		else if (b)
			return n;
		else
			return v[v.size() - 1] + 1;
	}
};
