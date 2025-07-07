#include <iostream>
class Solution {
public:
    bool isPowerOfFour(int n) {
        if (n == 1) return true;
        if (n <= 0) return false;
		return n % 4 == 0 && isPowerOfFour(n / 4);
    }
};

int main(void) {
	Solution sol = {};
	std::cout << sol.isPowerOfFour(4) << '\n';
	std::cout << sol.isPowerOfFour(6) << '\n';
	return 0;
}
