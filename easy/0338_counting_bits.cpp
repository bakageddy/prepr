#include <iostream>
#include <vector>
using std::vector;

static vector<int> lookup;

class Solution {
public:
	int count_bits(int n) {
		if (n == 0) return 0;
		int count = 0;
		while (n) {
			if (n & 1) count++;
			n >>= 1;
		}
		return count;
	}

    vector<int> countBits(int n) {
		vector<int> ans = {0};
		int len = lookup.size();
		for (int i = 1; i < n; i++) {
			if (i < len) {
				ans.push_back(lookup[i]);
			} else {
				int count = count_bits(i);
				lookup.push_back(count);
				ans.push_back(count);
			}
		}
		return ans;
    }
};

int main(void) {
	Solution sol = {};
	auto ans = sol.countBits(4);
	for (auto& x : ans) {
		std::cout << x << ' ';
	}
	std::cout << '\n';
	return 0;
}
