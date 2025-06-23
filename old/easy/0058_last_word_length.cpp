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

class Solution2 {
public:
	int lengthOfLastWord(std::string s) {
		int word_len = 0;
		int i = s.length() - 1;
		for (; i >= 0 && s[i] == ' '; i--);
		for (; i >= 0 && s[i] != ' '; i--, word_len++);
		return word_len;
	}
};
