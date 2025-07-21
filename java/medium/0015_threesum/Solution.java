import java.util.List;
import java.util.Set;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.HashSet;

// TODO: Solve this problem
public class Solution {
	public List<List<Integer>> threeSum(int[] nums) {
		List<List<Integer>> acc = new ArrayList<>();
		Set<int[]> seen = new HashSet<>();

		Arrays.sort(nums);
		for (int i = 0; i < nums.length - 2; i++) {
			int current_value = nums[i];
			int target = -current_value;

			int j = i + 1;
			int k = nums.length - 1;
			int sum = nums[i] + nums[j] + nums[k];
			while (sum != 0) {
				if (nums[j] + nums[k] > target) k--;
				else if (nums[j] + nums[k] < target) j++;

				sum = nums[i] + nums[j] + nums[k];
			}

			int[] ans = {nums[i], nums[j], nums[k]};
			if (!seen.contains(ans)) {
				acc.addLast(new ArrayList<>(Arrays.asList(nums[i], nums[j], nums[k])));
				continue;
			}
			while (j < k - 1 && nums[j] == nums[j + 1]) j++;
		}

		return acc;
    }
}
