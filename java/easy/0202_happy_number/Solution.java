package dev.bakageddy.prepr;

import java.util.HashSet;

public class Solution {
    public boolean isHappy(int n) {
		HashSet<Integer> seen = new HashSet<>();
		while (n != 1) {
			if (seen.contains(n)) {
				break;
			} else {
				seen.add(n);
				n = sumOfSquares(n);
			}
		}
		return n == 1;
    }

	public int sumOfSquares(int n) {
		int sum = 0;
		while (n != 0) {
			int rem = n % 10;
			sum += (rem * rem);
			n /= 10;
		}
		return sum;
	}
}
