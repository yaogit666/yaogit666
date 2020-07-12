#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
	bool cmp(int x, int y)
	{
		return x > y;
	}
	int findKthLargest(vector<int>& nums, int k) {
		vector<int> v;
		sort(nums.begin(), nums.end());
		int len = nums.size();
		for (int i = 1; i < len; i++)
		{
			if (nums[i] != nums[i - 1])
				v.push_back(nums[i - 1]);
		}
		if (nums[len - 1] != nums[len - 2])
			v.push_back(nums[len - 1]);
		sort(v.begin(), v.end(), cmp);
		int res = 0;
		int i = 0;
		while (k--)
		{
			res = v[i++];
		}
		return res;
	}
	int main()
	{
		vector<int> nums;
		int n = 0;
		while (cin >> n)
		{
			nums.push_back(n);
			if (cin.get() == '\n')
				break;
		}
		int res = findKthLargest(nums, 4);
		cout << res << endl;
		system("pause");
		return 0;
	}