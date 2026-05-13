#include <cstdlib>
#include <iostream>
#include <limits>
class Solution {
public:
	long long divide_helper(long long dividend, long long divisor) {
		if (dividend == std::numeric_limits<int>::min() && divisor == -1) return std::numeric_limits<int>::max();
		if (divisor == 1) return dividend;
		if (dividend == divisor) return 1;
		if (dividend == 0) return 0;

		if (dividend < 0 && divisor < 0) return divide_helper(-dividend, -divisor);
		if (dividend < 0) return -divide_helper(-dividend, divisor);
		if (divisor < 0) return -divide_helper(dividend, -divisor);

		long long quo = 0;
		while (divisor < dividend) {
			dividend -= divisor;
			quo++;
		}
		if (quo > std::numeric_limits<int>::max()) return std::numeric_limits<int>::max();
		return quo;

	}
    int divide(int dividend, int divisor) {
		return (int) divide_helper(dividend, divisor);
    }
};

int main(void) {
	Solution sol = {};
	std::cout << sol.divide(-2147483648, -1) << '\n';
	std::cout << sol.divide(7, 2) << '\n';
	return 0;
}
