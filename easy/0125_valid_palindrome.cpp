#include <cctype>
#include <iostream>
#include <string>
using std::string;

class Solution {
public:
	bool is_eq_ics(char a, char b) {
		return tolower(a) == tolower(b);
	}
    bool isPalindrome(string s) {
		int i = 0;
		int j = s.length() - 1;
		while (i <= j) {
			if (isspace(s[i]) || ispunct(s[i])) {
				i++;
				continue;
			}
			if (isspace(s[j]) || ispunct(s[j])) {
				j--;
				continue;
			}

			if (!is_eq_ics(s[i], s[j])) return false;
			i++;
			j--;
		}
		return true;
    }
};

int main(void) {
	Solution sol = {};
	std::cout << sol.isPalindrome("race : car") << '\n';
	std::cout << sol.isPalindrome("a man, a plan, a canal: Panama") << '\n';
	return 0;
}
