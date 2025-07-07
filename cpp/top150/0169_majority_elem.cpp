#include <iostream>
#include <vector>

using std::vector;
class Solution {
public:
    int majorityElement(vector<int>& nums) {
		int majority = nums[0];
		int count = 1;
		for (int i = 1; i < nums.size(); i++) {
			if (count == 0) {
				majority = nums[i];
				count++;
			} else if (nums[i] == majority) {
				count++;
			} else {
				count--;
			}
		}
		return majority;
    }
};

int main(void) {
	Solution sol = {};
	vector<int> nums = {5, 5, 5, 4, 3, 5};
	int ans = sol.majorityElement(nums);
	std::cout << ans << '\n';
	return 0;
}
