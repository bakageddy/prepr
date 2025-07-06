package dev.bakageddy.prepr;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

public class Solution {
    public List<List<Integer>> generate(int numRows) {
		List<List<Integer>> ans = new ArrayList<>();
		if (numRows == 1) {
			ans.addLast(Arrays.asList(1));
		} else if (numRows == 2) {
			ans.addLast(Arrays.asList(1));
			ans.addLast(Arrays.asList(1, 1));
		} else {
			ans.addLast(Arrays.asList(1));
			ans.addLast(Arrays.asList(1, 1));
			for (int i = 2; i < numRows; i++) {
				ArrayList<Integer> temp = new ArrayList<>(Arrays.asList(1));
				for (int j = 1; j < i; j++) {
					temp.addLast(
						ans.get(i - 1).get(j - 1) + ans.get(i - 1).get(j)
					);
				}
				temp.addLast(1);
				ans.addLast(temp);
			}
		}
		return ans;
    }
}
