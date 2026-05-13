#include <algorithm>
#include <iostream>
#include <vector>
using std::vector;

class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
		std::make_heap(stones.begin(), stones.end());
		while (stones.size() > 1) {
			std::pop_heap(stones.begin(), stones.end());
			int a = stones.back();
			stones.pop_back();

			std::pop_heap(stones.begin(), stones.end());
			int b = stones.back();
			stones.pop_back();

			if (a == b) {
				continue;
			} else {
				stones.push_back(a - b);
				std::push_heap(stones.begin(), stones.end());
			}
		}
		return stones.size() == 0 ? 0 : stones[0];
    }
};

int main(void) {
	vector<int> nums = {7, 2, 3, 5, 8};
	Solution sol = {};
	int ans = sol.lastStoneWeight(nums);
	std::cout << ans << '\n';
	return 0;
}
