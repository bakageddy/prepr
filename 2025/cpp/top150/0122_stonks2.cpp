#include <vector>
using std::vector;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
		int prev = prices[0];
		int total_profit = 0;
		for (int i = 1; i < prices.size(); i++) {
			if (prev < prices[i]) {
				total_profit += prices[i] - prev;
				prev = prices[i];
			}
		}
		return total_profit;
    }
};
