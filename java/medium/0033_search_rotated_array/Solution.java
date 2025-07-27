import java.util.Optional;

public class Solution {
    public int search(int[] nums, int target) {
        int len = nums.length;
        if (len == 0) return -1;
        if (len == 1 && nums[0] != target) return -1;
        if (len == 1) return 0;

		int rotated_point = 0;
		int start = 0;
		int end = len - 1;

		while (start < len && end >= 0 && start <= end) {
			int mid = start + (end - start) / 2;
			if (nums[mid] < nums[0]) {
				end = mid - 1;
			} else if (nums[mid] > nums[nums.length - 1]) {
				start = mid + 1;
			} else {
				if (nums[mid] > nums[mid + 1]) rotated_point = mid + 1;
				else if (mid > 0 && nums[mid] < nums[mid - 1]) rotated_point = mid;
				break;
			}
		}
        if (rotated_point == 0) rotated_point = start + (end - start) / 2;

		Optional<Integer> result = binary_search(nums, 0, rotated_point - 1, target);
		if (!result.isEmpty()) {
			return result.get();
		}

		result = binary_search(nums, rotated_point, nums.length - 1, target);
		if (!result.isEmpty()) {
			return result.get();
		}

		return -1;
    }

	public static Optional<Integer> binary_search(int[] nums, int start, int end, int target) {
		while (start <= end) {
			int mid = start + (end - start) / 2;
			if (nums[mid] > target) {
				end = mid - 1;
			} else if (nums[mid] < target) {
				start = mid + 1;
			} else {
				return Optional.of(mid);
			}
		}

		return Optional.empty();
	}

	public static void main(String[] args) {
		Solution sol = new Solution();
		int[] nums = {2, 3, 4, 5, 6, 7, 0, 1};
		int result = sol.search(nums, 1);
		System.out.println(result);
	}
}
