#include <iostream>
#include <vector>

using std::vector;

class Solution {
public:
	vector<int> searchRange(vector<int>& nums, int target) {
		vector<int> ans = vector<int>(2);
		int low = 0;
		int high = nums.size() - 1;
		int start, end;
		while (low <= high) {
			int mid = low + (high - low) / 2;
			if (nums[mid] == target) {
				start = mid;
				end = mid;
				break;
			} else if (nums[mid] > target) {
				high = mid - 1;
			} else {
				low = mid + 1;
			}
		}

		if (low > high) {
			return {-1, -1};
		}

		while (start > 0 && nums[start - 1] == target) {
			start -= 1;
		}

		while (end < nums.size() - 1 && nums[end + 1] == target) {
			end += 1;
		}

		ans[0] = start;
		ans[1] = end;

		return ans;
	}
};

int main() {
	vector<int> nums = {1, 2, 4, 4, 4, 4, 4, 5};
	Solution sol = Solution();
	vector<int> ans = sol.searchRange(nums, 4);
	for (int x : ans) {
		std::cout << x << ' ';
	}
	std::cout << '\n';
	return 0;
}
