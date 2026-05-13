#include <algorithm>
#include <vector>
using std::vector;

// I really don't understand this problem and i don't want to understand this.

class Solution {
public:
    int hIndex(vector<int>& citations) {
		int n = citations.size();
		std::sort(citations.begin(), citations.end());
		for (int i = 0; i < citations.size(); i++) {
			if (n - i <= citations[i]) {
				return n - i;
			}
		}
		return 0;
    }
};
