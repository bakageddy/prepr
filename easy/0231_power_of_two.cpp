#include <iostream>
class Solution {
public:
    bool isPowerOfTwo(int n) {
		if (n == 0) return false;
		while (n != 0) {
			if (n & 1) {
				n >>= 1; 
				break;
			}
			n >>= 1;
		}
		while (n != 0) {
			if (n & 1) return false;
			n >>= 1;
		}
		return true;
    }
};

int main(void) {
	Solution sol = {};
	std::cout << sol.isPowerOfTwo(8) << '\n';
	std::cout << sol.isPowerOfTwo(9) << '\n';
	return 0;
}
