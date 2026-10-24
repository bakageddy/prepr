#include <cmath>

class Solution {
public:
    int smallestNumber(int n) {
		int count = 0;
		while (n != 0) {
			n >>= 1;
			count += 1;
		}
		return std::pow(2, count) - 1;
    }
};
