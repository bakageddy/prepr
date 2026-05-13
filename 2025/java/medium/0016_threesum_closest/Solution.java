import java.util.Arrays;

public class Solution {
    public int threeSumClosest(int[] nums, int target) {
		int len = nums.length;
		int min_sum = Integer.MAX_VALUE;
		Arrays.sort(nums);
		for (int i = 0; i < len - 2; i++) {
			int low = i + 1;
			int high = len - 1;
			while (low < high) {
				int sum = nums[i] + nums[low] + nums[high];
				if (Math.abs(min_sum - target) > Math.abs(sum - target)) {
					min_sum = sum;
				}

				if (sum < target) {
					low++;
				} else if (sum > target) {
					high--;
				} else {
					return target;
				}
			}
		}
		return min_sum;
    }
}
