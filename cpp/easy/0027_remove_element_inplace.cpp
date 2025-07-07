#include <iostream>
#include <vector>

class Solution {
public:
    int removeElement(std::vector<int>& nums, int val) {
		int left = 0, right = nums.size();
		while (left < right) {
			if (nums[left] == val && nums[right] != val) {
				nums[left] = nums[right];
				left++;
				right--;
			} else if (nums[left] != val) {
				left++;
			}
		}
		return left;
    }
};

int main(void) {
	std::vector<int> nums = {3, 2, 2, 3};
	Solution sol = {};
	int ans = sol.removeElement(nums, 3);
	std::cout << "Ans: " << ans << '\n';
	std::cout << "Elements: ";
	for (auto i : nums) {
		std::cout << i << " ";
	}
	std::cout << '\n';
	return 0;
}
