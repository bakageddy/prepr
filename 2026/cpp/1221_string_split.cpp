#include <string>
using std::string;

class Solution {
  public:
    int balancedStringSplit(string s) {
		int lcount = 0;
		int rcount = 0;
		int split_count = 0;
		for (char c : s) {
			if (c == 'R') {
				rcount += 1;
			}
			if (c == 'L') {
				lcount += 1;
			}

			if (lcount != 0 && rcount != 0 && rcount == lcount) {
				split_count += 1;
				lcount = 0;
				rcount = 0;
			}
		}

		if (lcount != 0 || rcount != 0) {
			split_count += 1;
		}

		return split_count;
	}
};
