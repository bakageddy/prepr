#include <vector>
using std::vector;

class Solution {
public:
    int majorityElement(vector<int>& nums) {
		int max = {};
		int count = 0;
		for (int i = 1; i < nums.size(); i++) {
			if (count == 0) {
				max = nums[i];
			} else if (max == nums[i]) {
				count++;
			} else {
				count--;
			}
		}
		return max;
    }
};
