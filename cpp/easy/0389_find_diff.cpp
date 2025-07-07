#include <string>
#include <array>

using std::array, std::string;
class Solution {
public:
    char findTheDifference(string s, string t) {
		array<int, 26> lookup_table = {0};
		for (int i = 0; i < t.size(); i++) {
			lookup_table[t[i] - 'a']++;
		}
		for (int i = 0; i < s.size(); i++) {
			lookup_table[s[i] - 'a']--;
		}
		for (int i = 0; i < lookup_table.size(); i++) {
			if (lookup_table[i] == 1) {
				return i + 'a';
			}
		}
		return 0;
    }
};
