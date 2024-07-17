#include <map>
class Solution {
public:
	std::map<int, int> memo = {{0, 0}, {1, 1}, {2, 2}};
    int climbStairs(int n) {
		if (n == 1) return 1;
		if (n == 2) return 2;
		int n_1 {}, n_2 {};
		auto result1 = this -> memo.find(n - 1);
		if (result1 != this -> memo.end()) {
			n_1 = result1->second;
		} else {
			n_1 = climbStairs(n - 1);
			this -> memo[n - 1] = n_1;
		}

		auto result2 = this -> memo.find(n - 2);
		if (result2 != this -> memo.end()) {
			n_2 = result2 -> second;
			this -> memo[n - 2] = n_2;
		}


		return n_1 + n_2;
    }
};
