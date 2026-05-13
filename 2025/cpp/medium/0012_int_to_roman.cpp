#include <iostream>
#include <string>
#include <array>
using std::string, std::array;

static std::array<string, 13> values = {
	"M",
	"CM",
	"D",
	"CD",
	"C",
	"XC",
	"L",
	"XL",
	"X",
	"IX",
	"V",
	"IV",
	"I"
};

static std::array<int, 13> int_values = {
	1000,
	900,
	500,
	400,
	100,
	90,
	50,
	40,
	10,
	9,
	5,
	4,
	1
};

class Solution {
public:
    string intToRoman(int num) {
		string ans = {};
		int i = 0;
		while (i < int_values.size() && num > 0) {
			if (num >= int_values[i]) {
				ans.append(values[i]);
				num -= int_values[i];
			} else {
				i++;
			}
		}
		return ans;
    }
};

int main(void) {
	Solution sol = {};
	std::cout << sol.intToRoman(1450) << '\n';
	return 0;
}
