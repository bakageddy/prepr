#include <cmath>
#include <iostream>
#include <string>

using std::string;

class Solution {
public:
    int titleToNumber(string columnTitle) {
		int ans = 0;
		for (int i = columnTitle.size() - 1; i >= 0; i--) {
			int d = columnTitle[i] - 'A' + 1;
			ans += ans * 26 + d;
		}
		return ans;
    }
};

int main(void) {
	Solution sol = {};
	std::cout << sol.titleToNumber("ZY") << '\n';
	return 0;
}
