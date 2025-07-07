#include <algorithm>
#include <vector>
#include <cassert>
#include <limits>
using std::vector;

class Solution {
public:
	int min_of(vector<int>& vals) {
		assert(vals.size() != 0);
		int min_val = std::numeric_limits<int>::max();
		int index_val = -1;
		for (int i = 0; i < vals.size(); i++) {
			if (min_val > vals[i]) {
				min_val = vals[i];
				index_val = i;
			}
		}
		return index_val;
	}

    int eliminateMaximum(vector<int>& dist, const vector<int>& speed) {
		for (int i = 0; i < dist.size(); i++) {
			int idx = min_of(dist);
			return i;
		}
    }
};
