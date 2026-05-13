#include <vector>
#include <iostream>

class Solution {
public:
    int removeElement(std::vector<int>& nums, int val) {
		if (nums.size() == 0) return 0;
		if (nums.size() == 1 && nums[0] == val) return 0;
		int overwrite = 0;
		for (int i = 0; i < nums.size(); i++) {
			if (nums[i] != val) {
				nums[overwrite] = nums[i];
				overwrite += 1;
			}
		}
		return overwrite;
	}
};

int main (int argc, char *argv[]) {
	std::vector<int> nums = {1, 2, 3, 3, 4, 5};
	Solution sol = {};
	std::cout << "Len: " << sol.removeElement(nums,  3) << '\n';
	for (int i = 0; i < nums.size(); i++) {
		std::cout << i << ' ' << nums[i] << ' ';
	}
	std::cout << '\n';
	return 0;
}
