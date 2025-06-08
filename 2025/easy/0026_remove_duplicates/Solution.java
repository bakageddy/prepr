public class Solution {
	public int removeDuplicates(int[] nums) {
		if (nums.length == 0) return 0;
		int i = 0;
		for (int j = 0; j < nums.length; j++) {
			if (nums[i] != nums[j]) {
				nums[++i] = nums[j];
			} else {
				nums[i] = nums[j];
			}
		}
		return i;
	}

	public static void main(String[] args) {
		int[] nums = {1, 1, 1, 1, 2, 2, 2, 2, 3, 4, 4, 4, 5, 5, 5};
		int[] expected = {1, 2, 3, 4, 5};
		Solution s = new Solution();
		int k = s.removeDuplicates(nums);
		for (int i = 0; i < nums.length; i++) {
			System.out.print(nums[i] + ",");
		}
		System.out.println();
		System.out.println(k);
	}
}
