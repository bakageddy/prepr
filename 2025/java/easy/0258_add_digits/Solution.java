public class Solution {
	// NOTE: Kinda proud to just come up with the solution without any help
	public int sumOfDigits(int num) {
		if (num == 0) return 0;
		if (num % 9 == 0) return 9;
		return num % 9;
	}
}
