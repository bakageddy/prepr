#include <string>
using std::string;
class Solution {
public:
    bool isSubsequence(string s, string t) {
		if (t.empty()) return false;
		if (s.empty()) return true;
		int i = 0;
		int j = 0;
		for (; i < s.size(); i++) {
			while (j < t.size() && t[j] != s[i]) {
				if (j == t.size()) return false;
				j++;
			}
		}
		return i == s.size();
    }
};
