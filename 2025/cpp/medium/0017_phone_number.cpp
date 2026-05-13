#include <iostream>
#include <vector>
#include <string>
#include <array>

using std::vector, std::string, std::array;

const static array<string, 8> lookup_table = {
	"abc",
	"def",
	"ghi",
	"jkl",
	"mno",
	"pqrs",
	"tuv",
	"wxyz"
};

class Solution {
public:
    vector<string> letterCombinations(string digits) {
		if (digits == "") return {};
		string value = lookup_table[digits[0] - '2'];
		if (digits.length() == 1) {
			vector<string> ans = {};
			ans.assign(value.length(), "");
			for (int i = 0; i < value.length(); i++) {
				ans[i].push_back(value[i]);
			}
			return ans;
		} else {
			vector<string> res = letterCombinations(digits.substr(1));
			vector<string> ans = {};
			for (int i = 0; i < value.length(); i++) {
				for (int j = 0; j < res.size(); j++) {
					ans.push_back(value[i] + res[j]);
				}
			}
			return ans;
		}
    }
};

int main(int argc, char *argv[]) {
	Solution sol = {};
	auto res = sol.letterCombinations("23");
	for (auto x : res) {
		std::cout << x << '\n';
	}
	return 0;
}
