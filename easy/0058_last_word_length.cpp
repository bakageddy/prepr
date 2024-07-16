#include <string>

class Solution {
public:
	int lengthOfLastWord(std::string s) {
		int word_len = 0;
		int i = s.length() - 1;
		while (true) {
			if (s[i] == ' ') {
				i--;
			} else {
				break;
			}
		}
		for (; i >= 0; i--) {
			if (s[i] == ' ') break;
			else word_len += 1;
		}
		return word_len;
	}
};
