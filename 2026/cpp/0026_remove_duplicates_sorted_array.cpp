#include <cassert>
#include <cstdint>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
  public:
    int removeDuplicates(vector<int> &nums) {
		auto len = nums.size();
		if (len == 0 || len == 1) {
			return len;
		}

		uint64_t read = 0;
		uint64_t write = 0;
		while (read < len) {
			if (nums[read] == nums[read + 1]) {
				read += 1;
				continue;
			} else {
				nums[write] = nums[read];
				read += 1;
				write += 1;
			}
		}
		return write;
	}
};

int main(int argc, char** argv) {
	vector<int> nums = {1, 2, 2, 3, 3, 3};
	Solution sol = {};
	int upper = sol.removeDuplicates(nums);
	for (int i = 0; i < upper; i++) {
		cout << nums[i] << ' ';
	}
	cout << '\n';
	return 0;
}
