#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int firstMissingPositive(int* nums, int numsLen) {
	vector<int> v;
	for (int i = 0; i < numsLen; i++)
	{
		v.push_back(nums[i]);
	}
	sort(v.begin(), v.end());
	int len = v.size() - 1;
	if (v[len] < 0)
		return 1;
	int key = 0;
	for (int i = 0; i < v.size() - 1; i++)
	{
		if (v[i] <= 0)
			key = i+1;
		else
			break;
	}
	int j = 1;
	for (int i = key; i < v.size(); i++)
	{
		if (v[i] != j)
			return j;
		j++;
	}
	return v[len] + 1;
}

int main()
{
	int nums[4] = {-1,1,0,-6};
	cout << firstMissingPositive(nums, 4) << endl;
	system("pause");
	return 0;
}