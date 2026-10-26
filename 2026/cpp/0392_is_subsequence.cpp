#include <iostream>
#include <string>
using namespace std;

class Solution {
  public:
    bool isSubsequence(string s, string t) {
        if (s.size() == 0) {
			return true;
        }
		int i = 0;
		int j = 0;
		for (int i = 0; i < s.size(); i++) {
			char c = s[i];
			bool found = false;
			while (j < t.size()) {
				if (t[j] == c) {
					found = true; 
					j += 1;
					break;
				}
				j += 1;
			}

			if (!found) {
				return false;
			}
		}
		return true;
    }
};

int main() {
	Solution sol = {};
	cout << sol.isSubsequence("abc", "accbdddc") << '\n';
	return 0;
}
