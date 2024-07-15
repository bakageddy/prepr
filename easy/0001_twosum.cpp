#include <iostream>
#include <map>
#include <vector>
class Solution {
public:
	Solution() {};
	std::vector<int> twoSum(std::vector<int>& nums, int target) {
		std::map<int, unsigned int> pairs {};
		for (unsigned int i = 0; i < nums.size(); i++) {
			int y = target - nums[i];
			auto found = pairs.find(y);
			if (found != pairs.end()) {
				return std::vector<int>{(int) i, (int) found -> second};
			} else {
				pairs.insert_or_assign(nums[i], i);
			}
		}
		return std::vector<int>{-1, -1};
	}
};

int main(void) {
	std::vector<int> nums = {2, 5, 7};
	auto sol = Solution();
	auto result = sol.twoSum(nums, 9);
	std::cout << result[0] << " " << result[1] << '\n';
	return 0;
}
