package dev.bakageddy.prepr;
public class Solution {
	public int[] plusOne(int[] digits) {
		int len = digits.length;
		if (digits[0] == 9) {
			int[] something = new int[len + 1];
			something[0] = 0;
			for (int i = 1; i < something.length; i++) {
				something[i] = digits[i-1];
			}
			digits = something;
			len = digits.length;
		}

		for (int i = len - 1; i >= 0; i--) {
			if (digits[i] == 9) {
				digits[i] = 0;
			} else {
				digits[i] += 1;
				break;
			}
		}
		return digits;
	}

	public static void main(String[] args) {
		int[] digits = {9, 9, 9, 9};
		int[] result = new Solution().plusOne(digits);
		for (int i = 0; i < result.length; i++) {
			System.out.print(result[i]);
		}
		System.out.println();
	}
}
