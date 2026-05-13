#include <vector>
using std::vector;
class Solution {
public:
    bool canJump(vector<int>& nums) {
		int jumps_left = 0;
		for (int i = 0; i < nums.size(); i++) {
			jumps_left += nums[i];
			jumps_left--;
			if (jumps_left == 0) return false;
		}
		return true;
    }
};
