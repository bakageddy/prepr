public class Solution {
    public int removeElement(int[] nums, int val) {
		int overwrite = 0;
		for (int visitor = 0; visitor < nums.length; visitor++) {
			if (nums[visitor] != val) {
				nums[overwrite] = nums[visitor];
				overwrite++;
			}
		}
		return overwrite;
    }
}
