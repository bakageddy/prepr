public class Solution {
	public static boolean willOverflow(long a, long b) {
        if (a == 0 || b == 0) return false;
        if (a > 0 && b > 0 && a > Long.MAX_VALUE / b) return true;
        if (a > 0 && b < 0 && b < Long.MIN_VALUE / a) return true;
        if (a < 0 && b > 0 && a < Long.MIN_VALUE / b) return true;
        return a < 0 && b < 0 && a < Long.MAX_VALUE / b;
    }
    public int myAtoi(String s) {
		if (s.isEmpty() || s.isBlank()) return 0;

		int i = 0;
		while (s.charAt(i) == ' ') {
			i++;
		}

		String trimmed = s.substring(i);
		String char_seq = null;

		boolean positive = true;
		char c = trimmed.charAt(0);
		if (c == '-') {
			positive = false;
			char_seq = trimmed.substring(1);
		} else if (c == '+') {
			positive = true;
			char_seq = trimmed.substring(1);
		} else {
			char_seq = trimmed;
		}

		long ans = 0;
		i = 0;
		while (i < char_seq.length()) {
			c = char_seq.charAt(i);

			if (!Character.isDigit(c)) return (int) ans;
            if (ans >= Integer.MAX_VALUE) break;

			ans *= 10;
			ans += c - '0';
			i++;
		}

		if (!positive) {
			ans = -ans;
		}

		if (ans >= Integer.MAX_VALUE)
			return Integer.MAX_VALUE;
		else if (ans <= Integer.MIN_VALUE)
			return Integer.MIN_VALUE;
		else
			return (int) ans;
    }

	public static void main(String[] args) {
		Solution sol = new Solution();
		int ans = sol.myAtoi("   -" + String.valueOf(Integer.MAX_VALUE));
		System.out.println(ans);
	}
}
