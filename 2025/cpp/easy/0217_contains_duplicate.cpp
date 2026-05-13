#include <vector>
#include <unordered_set>
using std::vector, std::unordered_set;

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
		unordered_set<int> seen = {};
		for (auto& x : nums) {
			if (seen.find(x) == seen.end()) {
				seen.insert(x);
			} else {
				return true;
			}
		}
		return false;
    }
};
