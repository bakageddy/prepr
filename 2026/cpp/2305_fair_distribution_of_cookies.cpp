#include <algorithm>
#include <limits>
#include <print>
#include <vector>

using std::vector;

class Solution {
  public:
    void helper(vector<int> &cookies, vector<int> &result, long long &min_fairness, int cursor) {
        if (cursor == cookies.size()) {
			auto max = std::max_element(result.begin(), result.end());
            min_fairness = std::min(min_fairness, static_cast<long long>(*max.base()));
            return;
        }

		for (int i = 0; i < result.size(); i++) {
			result[i] += cookies[cursor];
			helper(cookies, result, min_fairness, cursor + 1);
			result[i] -= cookies[cursor];
		}
    }
    int distributeCookies(vector<int> &cookies, int k) {
        vector<int> result = std::vector<int>(k, 0);
        long long min_fairness = std::numeric_limits<long long>::max();
        helper(cookies, result, min_fairness, 0);
        return min_fairness;
    }
};

int main(void) {
    Solution sol = {};
    vector<int> cookies = {8, 15, 8, 10, 20};
    sol.distributeCookies(cookies, 2);
    return 0;
}
