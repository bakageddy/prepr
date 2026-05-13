#include <cctype>
#include <string>
using std::string;

class Solution {
public:
	bool isVowel(char c) {
		c = tolower(c);
		return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
	}
    string reverseVowels(string s) {
		int i = 0;
		int j = s.size() - 1;
		while (i <= j) {
			if (isVowel(s[i]) && isVowel(s[j])) {
				char c = s[i];
				s[i] = s[j];
				s[j] = c;
				i++;
				j--;
			} else if (isVowel(s[i])) {
				j--;
			} else if (isVowel(s[j])){ 
				i++;
			} else {
				i++;
				j--;
			}
		}
		return s;
    }
};
