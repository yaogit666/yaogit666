class Solution {
public:
	int findLengthOfLCIS(vector<int>& nums) {
		int len = nums.size();
		if (len == 0)
			return 0;
		vector<int> dp(len, 0);
		dp[0] = 1;
		for (int i = 1; i < len; i++)
		{
			if (nums[i] > nums[i - 1])
				dp[i] = dp[i - 1] + 1;
			else
				dp[i] = 1;
		}
		int maxN = 0;
		for (int i = 0; i < len; i++)
		{
			maxN = max(dp[i], maxN);
		}
		return maxN;
	}
};