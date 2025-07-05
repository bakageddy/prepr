package dev.bakageddy.prepr;
import java.util.HashMap;

public class Solution {

	private HashMap<Integer, Integer> memo;
	public Solution() {
		memo = new HashMap<>();
		memo.put(1, 1);
		memo.put(2, 2);
		memo.put(3, 3);
	}

	public int climbStairs(int n) {
		if (this.memo.containsKey(n)) {
			return memo.get(n);
		} else {
			int result = climbStairs(n - 1) + climbStairs(n - 2);
			memo.put(n, result);
			return result;
		}
	}
}
