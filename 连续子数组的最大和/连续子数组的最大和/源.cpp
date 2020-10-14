class Solution {
public:
	int maxSubArray(vector<int>& nums) {
		int sum;
		int maxS = INT_MIN;
		for (int i = 0; i < nums.size(); i++)
		{
			if (sum < 0)
				sum = nums[i];
			else
				sum += nums[i];

			if (sum > maxS)
				maxS = sum;
		}
		return maxS;
	}
};