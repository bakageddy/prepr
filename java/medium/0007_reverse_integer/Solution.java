public class Solution {
    public int reverse(int x) {
		if (x == Integer.MAX_VALUE) return 0;
		if (x == Integer.MIN_VALUE) return 0;
		if (x == 0) return 0;
		if (x < 0) return -reverse(-x);

		int rev = 0;
		while (x > 0) {
			int rem = x % 10;
			rev += rem;
			rev *= 10;
			x /= 10;
		}
		return rev;
    }
}
