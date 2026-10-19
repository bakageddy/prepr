#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
  public:
    string longestCommonPrefix(vector<string> &strs) {
        if (strs.empty())
            return "";
        if (strs.size() == 1)
            return strs[0];

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

    string longestCommonPrefixFast(vector<string> &strs) {
        if (strs.empty())
            return "";
        if (strs.size() == 1)
            return strs[0];
        sort(strs.begin(), strs.end());
		string result = "";
        auto first = strs[0];
        auto last = strs[strs.size() - 1];
        auto min = std::min(first.size(), last.size());
        for (int i = 0; i < min; i++) {
            if (first[i] != last[i]) {
                return result;
            } else {
				result.push_back(first[i]);
			}
        }
        return result;
    }
};

int main() {
    Solution sol = {};
    vector<string> input = {"long", "longlong"};
    auto ans = sol.longestCommonPrefix(input);
    cout << "Answer: " << ans << '\n';
}
