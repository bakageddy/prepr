#include <vector>
using std::vector;

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int len = nums.size();
        long long sum = 0;
        long long expected_sum = (len) * (len + 1) * 0.5;
        for (auto x : nums) {
            sum += x;
        }
        return expected_sum - sum;
    }
};
