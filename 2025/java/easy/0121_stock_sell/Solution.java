package dev.bakageddy.prepr;

public class Solution {
    public int maxProfit(int[] prices) {
		int min_price = Integer.MAX_VALUE;
		int max_profit = Integer.MIN_VALUE;
		for (int i = 0; i < prices.length; i++) {
			min_price = prices[i] < min_price ? prices[i] : min_price;
			int profit_today = prices[i] - min_price;
			max_profit = max_profit < profit_today ? profit_today : max_profit;
		}
		return max_profit;
    }
}
