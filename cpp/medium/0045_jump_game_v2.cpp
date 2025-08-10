#include <iostream>
#include <limits>
#include <vector>

using std::vector;

class Solution {
public:
	int min = std::numeric_limits<int>::max();
    int jump(vector<int>& nums) {
		return dfs(nums, 0, 0);
    }

	int dfs(vector<int>& nums, int curr, int count) {
		if (curr >= nums.size()) {
			return std::numeric_limits<int>::max();
		}

		if (curr == nums.size() - 1) {
			return count + 1;
		}

		if (nums[curr] == 0) return std::numeric_limits<int>::max();
		for (int i = 1; i < nums[curr]; i++) {
			int res = dfs(nums, curr + i, count + 1);
			if (res < min) {
				min = res;
			}
		}
		return min;
	}
};

int main(void) {
	Solution sol = {};
	vector<int> nums = {2, 3, 1, 1, 4};
	int res = sol.jump(nums);
	std::cout << res << '\n';
	return 0;
}
