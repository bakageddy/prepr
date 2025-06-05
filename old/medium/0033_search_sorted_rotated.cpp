#include <iostream>
#include <vector>

using std::vector;

// 4 5 6 7 0 1 2 3
// 0 1 2 3 4 5 6 7

class Solution {
public:
    int find_pivot(vector<int>& nums) {
		if (nums.size() == 1) return 0;
        int lo = 0;
        int hi = nums.size();
        while (lo < hi) {
            int mid = lo + (hi - lo) / 2;
            if (nums[mid] < nums[mid - 1]) {
				return mid;
			} else if (nums[mid] > nums[mid - 1]){
				lo = mid + 1;
			} else {
				hi = mid - 1;
			}
        }
		return -1;
    }
    int search(vector<int>& nums, int target) {
		int pivot = find_pivot(nums);
		if (pivot == -1) return -1;
		int lo = pivot;
		int hi = nums.size();

		while (lo < hi) {
			int mid = lo + (hi - lo) / 2;
			if (nums[mid] == target) return mid;
			else if (nums[mid] > target) hi = mid - 1;
			else lo = mid + 1;
		}
		lo = 0;
		hi = pivot;
		while (lo < hi) {
			int mid = lo + (hi - lo) / 2;
			if (nums[mid] == target) return mid;
			else if (nums[mid] > target) hi = mid - 1;
			else lo = mid + 1;
		}
		return -1;
    }
};

int main(void) {
	vector<int> nums = {4, 5,6,7, 0, 1, 2};
	Solution sol = {};
	std::cout << sol.find_pivot(nums) << '\n';
	std::cout << sol.search(nums, 0) << '\n';
	return 0;
}
