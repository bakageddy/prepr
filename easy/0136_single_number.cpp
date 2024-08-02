#include <vector>
using std::vector;

// a ^ a = 0
// a ^ 0 = a
// only the single element will be left out

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int field = 0;
        for (auto& i : nums) {
            field ^= i;
        }
        return field;
    }
};
