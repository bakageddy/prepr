#include <vector>
using std::vector;

class Solution {
public:
    int majorityElement(vector<int>& nums) {
		int max = {};
		int count = 0;
		for (int i = 0; i < nums.size(); i++) {
			if (count == 0) {
				max = nums[i];
                count++;
			} else if (max == nums[i]) {
				count++;
			} else {
				count--;
			}
		}
		return max;
    }
};
