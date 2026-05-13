#include <limits>
#include <string>

using std::string;

class Solution {
public:
	bool isDigit(char c) {
		return c >= '0' && c <= '9';
	}
	inline bool isWhiteSpace(char c) {
		return c == ' ' || c == '\n' || c == '\r' || c == '\t';
	}
    int myAtoi(string s) {
		int ans = {};
		int i = 0;
		bool isPositive = true;
		// Skip Whitespace
		while (i < s.size() && isWhiteSpace(s[i])) i++;
		if (s[i] == '+') {
			isPositive = true;
			i++;
		} else if (s[i] == '-') {
			isPositive = false;
			i++;
		}
		while (i < s.size() && isDigit(s[i])) {
			int digit = s[i] - '0';
			long long intermediate = ans * 10LL + digit;
			if (intermediate >= std::numeric_limits<int>::max()) {
				if (isPositive) return std::numeric_limits<int>::max();
                else if (-intermediate <= std::numeric_limits<int>::min()) return std::numeric_limits<int>::min();
			}
			ans = (int) intermediate;
			i++;
		}
		if (!isPositive)
            return -ans;
		return ans;
    }
};
