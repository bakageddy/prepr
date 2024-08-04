#include <iostream>
#include <vector>

using std::vector;

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
		for (int i = 0; i < nums.size(); i++) {
			if (nums[i] != 0) {
				int j = i - 1;
				while (j >= 0 && nums[j] == 0) {
					int temp = nums[j + 1];
					nums[j + 1] = nums[j];
					nums[j] = temp;
					j--;
				}
			}
		}
    }
};

int main(void) {
	vector<int> ans = {0, 1, 0, 3, 0, 3, 4};
	Solution sol = {};
	sol.moveZeroes(ans);
	for (auto& x : ans) {
		std::cout << x << ' ';
	}
	std::cout << '\n';
	return 0;
}
