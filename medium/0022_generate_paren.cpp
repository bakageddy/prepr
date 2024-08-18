#include <iostream>
#include <string>
#include <vector>
using std::string, std::vector;
class Solution {
	void dfs(int open, int close, int n, string buffer, vector<string>& results) {
		if (open == n && close == n) {
			results.push_back(buffer);
			return;
		}
		if (open < n) {
			dfs(open + 1, close, n, buffer + "(", results);
		}
		if (close < open) {
			dfs(open, close + 1, n, buffer + ")", results);
		}
	}
public:
    vector<string> generateParenthesis(int n) {
		vector<string> res = {};
		dfs(0, 0, n, "", res);
		return res;
    }
};

int main(void) {
	Solution sol = {};
	auto ans = sol.generateParenthesis(4);
	for (auto x : ans) {
		std::cout << x << '\n';
	}
	return 0;
}
