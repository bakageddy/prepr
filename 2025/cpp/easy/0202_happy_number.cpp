#include <unordered_set>
class Solution {
public:
	static inline int sum_of_squares(int x) {
		int sum = 0;
		while (x != 0) {
			int rem = x % 10;
			sum += rem * rem;
			x /= 10;
		}
		return sum;
	}
    bool isHappy(int n) {
		std::unordered_set<int> seen = {};
		while (true) {
			int sum = sum_of_squares(n);
			if (sum == 1) {
				return true;
			} else if (seen.find(sum) != seen.end()) {
				return false;
			} else {
				seen.insert(sum);
				n = sum;
			}
		}
    }
};

