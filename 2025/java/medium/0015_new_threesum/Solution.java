import java.util.List;
import java.util.Set;
import java.util.HashSet;
import java.util.ArrayList;
import java.util.Arrays;

public class Solution {
    public List<List<Integer>> threeSum(int[] nums) {
        int len = nums.length;
		Arrays.sort(nums);

		List<List<Integer>> acc = new ArrayList<>();
		Set<List<Integer>> seen = new HashSet<>();
		for (int i = 0; i < len - 2; i++) {
			int low = i + 1;
			int high = len - 1;
			while (low < high) {
				int sum = nums[i] + nums[low] + nums[high];
				if (sum > 0) {
					high--;
				} else if (sum < 0) {
					low++;
				} else {
					seen.add(Arrays.asList(nums[i], nums[low], nums[high]));
					low++;
					high--;
				}
			}
		}

		for (var x : seen) {
			acc.addLast(x);
		}
		return acc;
    }


	public static void main(String[] args) {
		Solution sol = new Solution();
		sol.threeSum(new int[]{1, 2, 3, -1, -1, 0});
	}
}
