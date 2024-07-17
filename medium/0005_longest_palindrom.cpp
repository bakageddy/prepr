#include <string>

class Solution {
public:
	std::string longestPalindrome(std::string& s) {
		int left = 0;
		int right = s.length() - 1;
		while (left <= right) {
			if (s[left] == s[right]) {
				left++;
				right--;
			}
		}
	}
};
