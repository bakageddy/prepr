#include <vector>

class Solution {
public:
    int removeElement(std::vector<int>& nums, int val) {
		if (nums.size() == 0) return 0;
		if (nums.size() == 1 && nums[0] == val) return 0;
		return 0;
	}
};
