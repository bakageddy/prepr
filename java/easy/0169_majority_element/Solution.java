package dev.bakageddy.prepr;

public class Solution {

	public int majorityElement(int[] nums) {
		int majority = 0;
		int count = 0;
		for (int n : nums) {
			if (count == 0) majority = n;
			count += majority == n ? 1 : -1;
		}
		return majority;
	}
}
