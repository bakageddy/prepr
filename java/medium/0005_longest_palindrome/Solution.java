public class Solution {
    public String longestPalindrome(String s) {
		int len = s.length();
		if (len == 0) return s;
		if (len == 1) return s;

		int palin_start = 0;
		int palin_end = 0;
		int palin_len = palin_end - palin_start + 1;

		for (int i = 0; i < len; i++) {
			int start = i;
			int end = i;
			while (start >= 0 && end < len) {
				if (s.charAt(start) != s.charAt(end)) {
					break;
				}
				int temp_len = end - start + 1;
				if (palin_len < temp_len) {
					palin_len = temp_len;
					palin_start = start;
					palin_end = end;
				}
				start--;
				end++;
			}

			start = i;
			end = i + 1;

			while (end < len && start >= 0) {
				if (s.charAt(start) != s.charAt(end)) {
					break;
				}
				int temp_len = end - start + 1;
				if (palin_len < temp_len) {
					palin_len = temp_len;
					palin_start = start;
					palin_end = end;
				}
				start--;
				end++;
			}
		}

		return s.substring(palin_start, palin_end + 1);
    }

	public static void main(String[] args) {
		Solution sol = new Solution();
		var result = sol.longestPalindrome("abcbaaa");
		System.out.println(result);
	}
}
