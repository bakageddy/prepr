#include <string>
#include <iostream>
#include <unordered_map>
class Solution {
public:
	int romanToInt(std::string s) {
		std::unordered_map<char, int> value_map = {
			{'I', 1},
			{'V', 5},
			{'X', 10},
			{'L', 50 },
			{'C', 100},
			{'D', 500},
			{'M', 1000},
		};
		if (s.size() == 0) return 0;
		int prev_value = 0;
		int roman_number = 0;
		for (auto i = s.end() - 1; i >= s.begin(); i--) {
			auto value = value_map.find(*i);
			if (value == value_map.end()) {
				return -1;
			} else {
				if (value->second < prev_value) {
					roman_number -= value -> second;
				} else {
					roman_number += value -> second;
				}
				prev_value = value -> second;
			}
		}
		return roman_number;
	}
};

int main(void) {
	Solution sol = {};
	std::cout << sol.romanToInt("VIII") << "\n";
	return 0;
}
