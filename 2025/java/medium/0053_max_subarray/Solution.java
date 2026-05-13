public class Solution {
    public int MaxSubArray(int[] nums) {
        int res = nums[0];
		int total = 0;
		for (int i = 0; i < nums.length; i++) {
			if (total < 0) total = 0;
			total += nums[i];
			res = Math.max(total, res);
		}
		return res;
    }
}
