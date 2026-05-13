package dev.bakageddy.prepr;

import java.util.HashMap;

public class Solution {
    public int[] twoSum(int[] nums, int target) {
		HashMap<Integer, Integer> lookup_table = new HashMap<>();
		int[] return_val = new int[2];
		for (int i = 0; i < nums.length; i++) {
			Integer lookup_key = target - nums[i];
			int value = lookup_table.getOrDefault(lookup_key, -1);
			if (value == -1) {
				lookup_table.put(nums[i], i);
				continue;
			} else {
				return_val[0] = value;
				return_val[1] = i;
				return return_val;
			}
		}
		System.out.println(lookup_table);
		return null;
    }
}
