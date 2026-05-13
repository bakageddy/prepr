#include <algorithm>
#include <iostream>
#include <limits>
#include <vector>

using std::vector;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
		int total = 0;
		int res = nums[0];
		for (int n : nums) {
			if (total < 0) {
				total = 0;
			}
			total += n;
			res = std::max(res, total);
		}
		return res;
    }
};

int main(void) {
	Solution sol = {};
	vector<int> nums = {1, 2, 3, 4, -1};
	int ans = sol.maxSubArray(nums);
	std::cout << ans << '\n';
}
