#include <cstdlib>
class Solution {
public:
    int mySqrt(int x) {
		double guess = 1;
		double diff;
		do {
			guess = 0.5 * (guess + (x / guess));
			diff = std::abs(x - (guess * guess));
		} while (diff >= 0.000001);
		return (int) guess;
    }
};
