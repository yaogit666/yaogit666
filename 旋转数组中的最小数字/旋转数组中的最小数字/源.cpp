class Solution {
public:
	int minArray(vector<int>& numbers) {
		int n = numbers.size();
		int left = 0, right = n - 1;
		while (left < right) {
			int mid = (left + right) >> 1;
			if (numbers[mid] > numbers[right]) left = mid + 1;
			else if (numbers[mid] == numbers[right]) right--;
			else right = mid;
		}
		return numbers[left];
	}
};