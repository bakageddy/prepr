#include <unordered_map>
#include <array>
#include <string>

using std::unordered_map, std::string, std::array;

class Solution {
public:
	int count_space(const string s) {
		int count = 0;
		for (auto& x : s) {
			if (x == ' ') count++;
		}
		return count;
	}

	string split_by_space(string& s) {
		int res = s.find_first_of(" ");
		string temp = s.substr(0, res);
		s = s.substr(res + 1);
		return temp;
	}

    bool wordPattern(string pattern, string s) {
		if (count_space(s) + 1 != pattern.length()) return false;
		unordered_map<string, char> table = {};
		std::array<string, 26> inv_table = {""};
		for (auto x : pattern) {
			string word = split_by_space(s);
			auto found = table.find(word);
			if (inv_table[x - 'a'] != "" && found == table.end()) {
				return false;
			} else if (found == table.end()) {
				inv_table[x - 'a'] = word;
				table[word] = x;
			} else if (x == found -> second && word == found -> first) {
				continue;
			} else {
				return false;
			}
		}
		return true;
	}
};



int main(void) {
	return 0;
}


