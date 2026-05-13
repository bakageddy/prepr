package dev.bakageddy.prepr;

public class Solution {
    public long minCuttingCost(int n, int m, int k) {
		if (n <= k && m <= k) return 0;
		long cost = 0;

		if (n >= k) {
			long partition = n - k;
			cost += (partition) * (n - partition);
		}

		if (m >= k) {
			long partition = m - k;
			cost += partition * (m - partition); 
		}

		return cost;
    }
}
