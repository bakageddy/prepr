package dev.bakageddy.prepr;

import java.util.ArrayList;
import java.util.List;

public class Solution {
    public List<String> summaryRanges(int[] nums) {
        if (nums.length == 0) return new ArrayList<>();
		int start = nums[0];
		int prev = nums[0];
		List<String> cont = new ArrayList<>();

		int i = 1;
		do {
			if (nums[i] != prev + 1) {
				String range = null;
				if (start == prev) {
					range = String.format("%d", start);
				} else {
					range = String.format("%d->%d", start, prev);
				}
				cont.add(range);
				start = nums[i];
			}
			prev = nums[i];
			i++;
		} while (i < nums.length);
		return cont;
    }
}
