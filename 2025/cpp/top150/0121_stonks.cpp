#include <vector>
using std::vector;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
		int buyingPrice = prices[0];
		int profit = 0;
		for (int i = 1; i < prices.size(); i++) {
			if (buyingPrice > prices[i]) {
				buyingPrice = prices[i];
			}
			profit = profit < (prices[i] - buyingPrice) ? prices[i] - buyingPrice : profit;
		}
		return profit;
    }
};
