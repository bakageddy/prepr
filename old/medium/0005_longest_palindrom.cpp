#include <iostream>
#include <string>
using std::string;

class Solution {
public:
    string longestPalindrome(string s) {
		int maxLen = 0;
		int start = 0;
		for (int i = 0; i < s.size(); i++) {
			int l = i;
			int r = i;
			while (l >= 0 && r < s.size() && s[l] == s[r]) {
				int newLen = r - l + 1;
				if (newLen > maxLen) {
					maxLen = newLen;
					start = l;
				}
				l--;
				r++;
			}
			l = i;
			r = i+1;
			while (l >= 0 && r < s.size() && s[l] == s[r]) {
				int newLen = r - l + 1;
				if (newLen > maxLen) {
					maxLen = newLen;
					start = l;
				}
				l--;
				r++;
			}
		}
		return s.substr(start, maxLen);
    }
};

int main(void) {
	Solution sol = {};
	std::cout << sol.longestPalindrome("abc") << '\n';
	return 0;
}
