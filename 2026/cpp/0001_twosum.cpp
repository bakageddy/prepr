#include <unordered_map>
#include <vector>

// 2, 3, 7, 10, 1
// target = 9
// j

using std::vector;
class Solution {
  public:
    vector<int> twoSum(vector<int> &nums, int target) {
        std::unordered_map<int, int> seen = {};
        for (int i = 0; i < nums.size(); i++) {
            int num = nums[i];
            int needs = target - num;
            if (seen.find(needs) == seen.end()) {
                seen[num] = i;
            } else {
                auto j = seen.at(needs);
                return {i, j};
            }
        }
        return {-1, -1};
    }
};
