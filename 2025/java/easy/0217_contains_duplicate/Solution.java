package dev.bakageddy.prepr;

import java.util.Arrays;
import java.util.HashSet;

public class Solution {
    public boolean containsDuplicate(int[] nums) {
		HashSet<Integer> seen = new HashSet<>();
		for (int x : nums) {
			if (seen.contains(x)) {
				return false;
			} else {
				seen.add(x);
			}
		}
		return true;
    }

    public boolean containsDuplicate(int[] nums, boolean sort) {
		Arrays.sort(nums);
		for (int i = 0; i < nums.length - 1; i++) {
			if (nums[i] == nums[i + 1]) {
				return true;
			}
		}
		return false;
    }


}
