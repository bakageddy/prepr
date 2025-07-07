package dev.bakageddy.prepr;

public class Solution {
	private boolean helper(int x) {
		int original = x;
		int rev = 0;
		while (original > 0) {
			rev *= 10;
			rev += original % 10;
			original /= 10;
		}
		return rev == x;
	}
    public boolean isPalindrome(int x) {
		if (x < 0) return false;
		else return helper(x);
    }
}
