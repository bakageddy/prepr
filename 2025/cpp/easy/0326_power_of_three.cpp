#include <iostream>
class Solution {
public:
    bool isPowerOfThree(int n) {
		if (n == 0) return false;
		while (n != 1) {
			if (n % 3 != 0) return false;
			n /= 3;
		}
		return true;
    }
};

int main(void) {
	Solution sol = {};
	std::cout << sol.isPowerOfThree(3) << '\n';
	std::cout << sol.isPowerOfThree(9) << '\n';
	std::cout << sol.isPowerOfThree(2) << '\n';
	return 0;
}
