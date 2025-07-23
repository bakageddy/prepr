import java.util.List;
import java.util.ArrayList;
import java.util.Set;
import java.util.HashSet;
import java.util.Arrays;

public class Solution {
	public List<List<Integer>> fourSum(int[] nums, int target) {
		List<List<Integer>> acc = new ArrayList<>();
		Set<List<Integer>> seen = new HashSet<>();
		Arrays.sort(nums);

		for (int i = 0; i < nums.length - 3; i++) {
			for (int j = i + 1; j < nums.length - 2; j++) {
				int low = j + 1;
				int high = nums.length - 1;

				while (low < high) {
					long sum = (long) nums[i] + (long) nums[j] + (long) nums[low] + (long) nums[high];
					if (sum > target) {
						high--;
					} else if (sum < target) {
						low++;
					} else if (sum == target) {
						seen.add(Arrays.asList(nums[i], nums[j], nums[low], nums[high]));
						high--;
						low++;
					}
				}
			}
		}

		for (var list : seen) {
			acc.addLast(list);
		}
		return acc;
	}
}
