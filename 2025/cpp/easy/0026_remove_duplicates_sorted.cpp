#include <iostream>
#include <vector>

class Solution {
public:
	int removeDuplicates(std::vector<int>& nums) {
		if (nums.size() == 0) return 0;
		if (nums.size() == 1) return 1;

		int right = 1, left = 1, len = nums.size();
		int prev_value = nums[0];

		while (right < len) {
			if (prev_value != nums[right]) {
				prev_value = nums[right];

				int temp = nums[right];
				nums[right] = nums[left];
				nums[left] = temp;

				left++;
				right++;
			} else {
				prev_value = nums[right];
				right++;
			}
		}
		return left;
	}
};

int main(void) {
	std::vector<int> nums {0, 1, 1, 2, 2, 3, 3, 4 ,4 , 4};
	Solution sol = {};
	int ans = sol.removeDuplicates(nums);

	std::cout << "Ans: " << ans << '\n';
	std::cout << "Vector: ";
	for (int i = 0; i < ans; i++) {
		std::cout << nums[i] << " ";
	}
	std::cout << '\n';

	return 0;
}
