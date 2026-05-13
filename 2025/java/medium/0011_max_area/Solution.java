public class Solution {
    public int maxArea(int[] height) {
		int left = 0;
		int right = height.length - 1;
		int max_vol = Integer.MIN_VALUE;
		while (left < right) {
			int computed_vol = (right - left) * (Integer.min(height[left], height[right]));
			max_vol = Integer.max(max_vol, computed_vol);

			if (height[left] < height[right]) {
				left++;
			} else {
				right--;
			}
		}
		return max_vol;
    }
}
