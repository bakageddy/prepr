
#include <iostream>
#include <vector>

class Solution {
public:
	int binary_search(std::vector<int>& nums, int target) {
		int low = 0;
		int high = nums.size() - 1;
		int mid;
		while (low <= high) {
			mid = (low + high) / 2;
			if (nums[mid] == target) {
				return mid;
			} else if (nums[mid] > target) {
				high = mid - 1;
			} else if (nums[mid] < target) {
				low = mid + 1;
			}
		}
		return low;
	}
    int searchInsert(std::vector<int>& nums, int target) {
		return binary_search(nums, target);
    }
};

int main(void) {
	Solution sol = {};
	std::vector<int> nums = {1, 3, 5, 6};
	std::cout << "Enter target: ";
	int target = {};
	std::cin >> target;
	int ans = sol.binary_search(nums, target);
	std::cout << "Ans: " << ans << '\n';
	return 0;
}
