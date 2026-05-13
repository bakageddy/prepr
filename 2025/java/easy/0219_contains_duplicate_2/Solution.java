package dev.bakageddy.prepr;

import java.util.HashMap;

public class Solution {
    public boolean containsNearbyDuplicate(int[] nums, int k) {
		HashMap<Integer, Integer> seen = new HashMap<>();
		for (int i = 0; i < nums.length; i++) {
			if (seen.containsKey(nums[i])) {
				int j = seen.get(nums[i]);
				if (Math.abs(i - j) <= 2) {
					return true;
				}
			} else {
				seen.put(nums[i], i);
			}
		}
		return false;
    }
}
