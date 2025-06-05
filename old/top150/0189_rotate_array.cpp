#include <iostream>
#include <vector>
using std::vector;

class Solution {
	void reverse(vector<int>& nums, int lo, int hi) {
		while (lo < hi) {
			int temp = nums[lo];
			nums[lo] = nums[hi];
			nums[hi] = temp;
			lo++;
			hi--;
		}
	}
public:
    void rotate(vector<int>& nums, int k) {
		if (k >= nums.size()) k %= nums.size();
		reverse(nums, 0, nums.size() - 1);
		reverse(nums, 0, k - 1);
		reverse(nums, k, nums.size() - 1);
    }
};

int main (int argc, char *argv[]) {
	vector<int> vec = {1, 2, 3, 4, 5, 6};
	Solution sol = {};
	sol.rotate(vec, 3);
	for (const auto& x: vec) {
		std::cout << x << ' ';
	}
	std::cout << '\n';
	return 0;
}

// 1 2 3 4 5 6
// 6 5 4 3 2 1
//
// 6 5 4 1 2 3
