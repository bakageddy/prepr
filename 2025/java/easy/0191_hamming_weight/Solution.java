package dev.bakageddy.prepr;

public class Solution {
	public static void main(String[] args) {
		int count = new Solution().hammingWeight(1 << 32);
		System.out.println(count);
	}
    public int hammingWeight(int n) {
		int count = 0;
		for (int i = 0; i < 32; i++) {
			if ((n & 1) == 1) {
				count++;
			}
		}
		return count;
    }
}
