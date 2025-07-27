public class Solution {
	public void nextPermutation(int nums[]) {
		int len = nums.length;
		int i = len - 1;
		while (i > 0 && nums[i - 1] >= nums[i]) {
			i--;
		}

		if (i == 0) {
			reverse(nums);
			return;
		}

		int j = len - 1;
		while (j >= i && nums[j] <= nums[i - 1]) {
			j--;
		}

		swap(nums, j, i - 1);
		reverse(nums, i, len - 1);
		return;
	}

	public static void reverse(int[] nums) {
		reverse(nums, 0, nums.length - 1);
	}

	public static void reverse(int[] nums, int start, int end) {
		int left = start;
		int right = end;
		while (left < right) {
			swap(nums, left, right);
			left++;
			right--;
		}
	}

	public static void swap(int[] nums, int a, int b) {
		int temp = nums[a];
		nums[a] = nums[b];
		nums[b] = temp;
	}

	public static void main(String[] args) {
		int[] nums = {0, 1, 2, 3, 4, 5};
		reverse(nums);
		for (int i = 0; i < nums.length; i++) {
			System.out.print(nums[i] + " ");
		}
		System.out.println("");
	}
}
