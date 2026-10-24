#include <array>
#include <cstdint>
#include <string>

using std::string;

class Solution {
public:
    bool digitCount(string num) {
		std::array<uint64_t, 10> lookup_table = {};
		for (char c : num) {
			lookup_table[c - '0'] += 1;
		}

		for (int i = 0; i < num.size(); i++) {
			char c = num.at(i);
			if (lookup_table[i] == (c - '0')) {
				continue;
			} else {
				return false;
			}
		}
		return true;
    }
};
