#include <limits>

class Solution {
public:
    int reverse(int x) {
        if (x == std::numeric_limits<int>::min()) {
            return 0;
        }
        bool minus = false;
        if (x < 0) {
            x = -x;
            minus = true;
        }
        int temp = 0;
        while (x > 0) {
            long long another_temp = temp * 10LL + x % 10;
            if (another_temp > std::numeric_limits<int>::max()) {
                return 0;
            }
            temp = another_temp;
            x = x / 10;
        }
        if (minus) {
            temp = -temp;
        }
        return temp;
    }
};
