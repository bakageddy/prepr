#include <string>
#include <array>
using std::string, std::array;

class Solution {
public:
    int firstUniqChar(string s) {
		array<int, 26> lookup_table = {0};
		for (auto& c : s) {
			lookup_table[c - 'a']++;
		}
		for (int i = 0; i < s.size(); i++) {
			if (lookup_table[s[i] - 'a'] == 1) {
				return i;
			}
		}
		return -1;
    }
};
