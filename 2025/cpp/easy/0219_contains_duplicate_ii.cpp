#include <unordered_map>
#include <vector>
using std::vector, std::unordered_map;

class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
		unordered_map<int, int> lookup = {};
		for (int i = 0; i < nums.size(); i++) {
			auto found = lookup.find(nums[i]);
			if (found != lookup.end()) {
				int j = found -> second;
				if (i - j <= k) {
					return true;
				}
			} else {
				lookup[nums[i]] = i;
			}
		}
		return false;
    }
};

int main(void) {
	vector<int> ans = {1, 2, 3, 1,2, 3};
	Solution sol = {};
	sol.containsNearbyDuplicate(ans, 2);
	return 0;
}
