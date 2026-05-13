#include <iostream>
#include <vector>
using std::vector;

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
		int len = nums.size();
		vector<int> output(len);
		int suffix = 1;
		for (int i = 0; i < len; i++) {
			output[i] = suffix;
			suffix *= nums[i];
		}
		int prefix = 1;
		for (int i = len - 1; i >= 0; i--) {
			output[i] *= prefix;
			prefix *= nums[i];
		}
		return output;
    }
};

int main(void) {
	vector<int> nums = {1, 2,3, 4, 5};
	Solution sol = {};
	auto ans = sol.productExceptSelf(nums);
	for (const auto& x : ans) {
		std::cout << x << ' ';
	}
	std::cout << '\n';
	return 0;
}
