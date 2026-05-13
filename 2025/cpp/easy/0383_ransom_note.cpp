#include <algorithm>
#include <iostream>
#include <string>

using std::string;

class Solution {
public:
	// You dont need to sort
	// You can just use a array lookup table and decrement count
	// a..z ∍ ransomeNote[i], 0 <= i < size
    bool canConstruct(string ransomNote, string magazine) {
		std::sort(ransomNote.begin(), ransomNote.end());
		std::sort(magazine.begin(), magazine.end());
		int i = 0;
		int j = 0;
		while (i < ransomNote.size() && j < magazine.size()) {
			if (ransomNote[i] == magazine[j]) {
				i++;
				j++;
			} else if(ransomNote[i] > magazine[j]) {
				j++;
			} else {
				return false;
			}
		}
		return i == ransomNote.size();
    }
};

int main(void) {
	Solution sol = {};
	std::cout << sol.canConstruct(string("aa"), string("aab")) << '\n';
	std::cout << sol.canConstruct(string("aa"), string("ab")) << '\n';
	return 0;
}
