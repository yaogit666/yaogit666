#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int search(vector<int>& nums, int target) {
	if (nums.empty())
		return -1;
	int left = 0;
	int right = nums.size() - 1;
	while (left <= right)
	{
		int mid = left + ((right - left) >> 1);
		if (nums[mid] == target)
			return mid;

		if (nums[mid] < nums[right]) {
			if (nums[mid] < target && target <= nums[right]) {
				left = mid + 1;
			}
			else {
				right = mid - 1;
			}
		}
		else if (nums[mid] >= nums[right]) {
			if (nums[left] <= target && target < nums[mid]) {
				right = mid - 1;
			}
			else {
				left = mid + 1;
			}
		}
	}
	return -1;
}

int main()
{
	vector<int> v;
	int n;
	while (cin >> n)
	{
		v.push_back(n);
		if (cin.get() == '\n')
			break;
	}
	cout << search(v, 1) << endl;
	system("pause");
	return 0;
}