#include <vector>
#include <iostream>

using std::vector;
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
		int len = nums.size();
		if (len == 1 || len == 2) return len;
		bool seenTwice = false;
		int overwrite = 1;
		int prev = nums[0];
		for (int i = 1; i < len; i++) {
			if (nums[i] != prev) {
				prev = nums[i];
				seenTwice = false;
				nums[overwrite++] = nums[i];
			} else if (nums[i] == prev && seenTwice == false) {
				seenTwice = true;
				nums[overwrite++] = nums[i];
			} else if (nums[i] == prev && seenTwice == true) {
				continue;
			}
		}
		return overwrite;
	}
};


int main (int argc, char *argv[]) {
	vector<int> nums = {1, 1, 1, 2, 2, 3, 4};
	Solution sol = {};
	int ans = sol.removeDuplicates(nums);
	std::cout << "Len: " << ans << '\n';
	for (int i = 0; i < ans; i++) {
		std::cout << nums[i] << ' ';
	}
	return 0;
}
