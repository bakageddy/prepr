#include <iostream>

class Solution {
public:
    bool isPerfectSquare(int num) {
		if (num < 0) return false;
		if (num == 0 || num == 1) return true;

		int low = 0;
		int high = num / 2;
		while (low <= high) {
			long long mid = low + (high - low) / 2;
			long long squared = mid * mid;
			if (squared == num) return true;
			else if (squared > num) high = mid - 1;
			else low = mid + 1;
		}
		return false;
    }
};

int main(void) {
	Solution sol = {};
	std::cout << sol.isPerfectSquare(100) << '\n';
	std::cout << sol.isPerfectSquare(100000001) << '\n';
	std::cout << sol.isPerfectSquare(9) << '\n';
	std::cout << sol.isPerfectSquare(14) << '\n';
	return 0;
}
