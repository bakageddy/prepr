#include <string>
using std::string;
class Solution {
  public:
    int minimumMoves(const string s) {
        int i = 0;
		int count = 0;
        while (i < s.size()) {
			if (s[i] == 'O') {
				i += 1;
			} else if (s[i] == 'X') {
				count += 1;
				i += 3;
			}
        }
        return count;
    }
};
