#include <iostream>
#include <cassert>
#include <vector>
using std::vector;

class Solution {
public:
	long long factorial(int n) {
		assert(n >= 0);

		if (n == 0) return 1;
		long long acc = 1;
		for (int i = 1; i <= n; i++) {
			acc *= i;
		}
		return acc;
	}

    vector<int> getRow(int rowIndex) {
		vector<int> row;
		// This works but overflows for int.
		// Try to implement this smartly by using binomial expansion.
		for (int i = 0; i < rowIndex; i++) {
			row.push_back(factorial(rowIndex) / (factorial(rowIndex - i) * factorial(i)));
		}
		row.push_back(1);
		return row;
    }
};

int main(void) {
	Solution sol = {};
	auto ans = sol.getRow(5);
	for (auto& i : ans) {
		std::cout << i << " ";
	}
	std::cout << '\n';
	return 0;
}
