#include <iostream>
#include <vector>
using std::vector;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
		if (nums.size() == 1) return 1;
		int prev = nums[0];
		int overwrite = 1;
		for (int i = 1; i < nums.size(); i++) {
			if (nums[i] != prev) {
				prev = nums[i];
				nums[overwrite++] = nums[i];
			}
		}
		return overwrite;
    }
};

int main(void) {
	vector<int> vec = {1,2 , 3, 3, 4 ,4, 5};
	Solution sol = {};
	int ans = sol.removeDuplicates(vec);
	for (int i = 0; i < ans; i++) {
		std::cout << vec[i] << ' ';
	}
	std::cout << '\n';
	return 0;
}
