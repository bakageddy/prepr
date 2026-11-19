#include <limits>
#include <vector>
#include <iostream>
using std::vector;

class Solution {
public:
	void backtrack(vector<int>& nums, int& answer, int cursor, int jumps) {
		if (cursor == nums.size() - 1) {
			answer = answer > jumps ? jumps : answer;
			return;
		}

		if (cursor >= nums.size()) {
			return;
		}

		int value = nums[cursor];
		for (int i = value; i >= 1; i--) {
			if (cursor + i > nums.size()) {
				continue;
			}

			backtrack(nums, answer, cursor + i, jumps + 1);
		}
	}
    int jump(vector<int>& nums) {
		int answer = std::numeric_limits<int>::max();
		backtrack(nums, answer, 0, 0);
		return answer;
    }
};

int main(void) {
	vector<int> nums = {5,6,4,4,6,9,4,4,7,4,4,8,2,6,8,1,5,9,6,5,2,7,9,7,9,6,9,4,1,6,8,8,4,4,2,0,3,8,5};
	Solution sol = {};
	int answer = sol.jump(nums);
	std::cout << answer << '\n';
	return 0;
}
