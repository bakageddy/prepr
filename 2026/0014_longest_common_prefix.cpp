#include <bits/stdc++.h>
#include <vector>

using namespace std;

class Solution {
public:
	string longestCommonPrefix(vector<string>& strs) {
		if (strs.empty()) return "";
		if (strs.size() == 1) return strs[0];

		// sort(strs.begin(), strs.end());
		string retval = "";
		string shortest = strs[0];
		for (int cursor = 0; cursor < shortest.size(); cursor++) {
			char c = shortest[cursor];
			for (int i = 1; i < strs.size(); i++) {
				if (strs[i][cursor] != c) {
					return retval;
				}
			}
			retval += shortest[cursor];
		}
		return retval;
	}
};

int main() {
	Solution sol = {};
	vector<string> input = {"long", "longlong"};
	auto ans = sol.longestCommonPrefix(input);
	cout << "Answer: " << ans << '\n';
}
