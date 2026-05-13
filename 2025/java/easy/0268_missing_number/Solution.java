package dev.bakageddy.prepr;

public class Solution {
    public int missingNumber(int[] nums) {
		int len = nums.length;
		int sum = (int) (len * (len + 1) * 0.5); // Guarnteed even number
		for (int i = 0; i < len; i++) {
			sum -= nums[i];
		}
		return sum;
    }
}
