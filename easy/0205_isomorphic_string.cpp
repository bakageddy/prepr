#include <string>
#include <unordered_map>

using std::string;
using std::unordered_map;

class Solution {
public:
    bool isIsomorphic(string s, string t) {
		if (s.size() != t.size()) return false;
		unordered_map<char, char> translation_table = {};
		translation_table.reserve(s.size());
		for (int i = 0; i < s.size(); i++) {
			auto result = translation_table.find(s[i]);
			if (result != translation_table.end() && result->second != t[i]) {
				return false;
			} else {
				translation_table[s[i]] = t[i];
			}
		}
		translation_table.clear();
		for (int i = 0; i < s.size(); i++) {
			auto result = translation_table.find(t[i]);
			if (result != translation_table.end() && result->second != s[i]) {
				return false;
			} else {
				translation_table[t[i]] = s[i];
			}
		}
		return true;
    }
};
