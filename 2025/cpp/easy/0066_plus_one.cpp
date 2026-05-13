#include <iostream>
#include <vector>

class Solution {
public:
	std::vector<int> plusOne(std::vector<int>& nums) {
		for (int i = nums.size() - 1; i >= 0; i--) {
			if (nums[i] == 9) {
				nums[i] = 0;
				continue;
			} else {
				nums[i] = nums[i] + 1;
				break;
			}
		}
		if (nums[0] == 0) {
			nums.insert(nums.begin(), 1);
		}
		return nums;
	}
};

int main(void) {
	std::vector<int> nums = {9, 9, 9, 9, 9};
	Solution sol = {};
	nums = sol.plusOne(nums);
	for (auto& i : nums) {
		std::cout << i << " ";
	}
	std::cout << '\n';
	return 0;
}
