vector<int> maxDisplayWindow(vector<int>& nums, int m) {
	vector<int> v;
	for (int i = 0; i <= nums.size() - m; i++)
	{
		int maxN = nums[i];
		for (int j = i + 1; j < m + i; j++)
		{
			if (maxN < nums[j])
				maxN = nums[j];
		}
		v.push_back(maxN);
	}
	return v;
}
};