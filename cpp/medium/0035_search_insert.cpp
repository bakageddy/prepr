#include <iostream>
#include <vector>

using std::vector;

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
		int lo = 0;
		int hi = nums.size() - 1;
		while (lo <= hi) {
			int mid = lo + (hi - lo) / 2;
			if (nums[mid] > target) {
				hi = mid - 1;
			} else if (nums[mid] < target) {
				lo = mid + 1;
			} else {
				return mid;
			}
		}
		return lo;
    }
};

int main(void) {
	Solution sol = Solution();
	vector<int> nums = {1, 2, 4, 6};
	auto ans = sol.searchInsert(nums, 5);
	std::cout << ans << '\n';
	nums.insert(nums.begin() + ans, 5);
	for (int x : nums) {
		std::cout << x << ' ';
	}
	std::cout << '\n';
	return 0;
}
