import java.util.HashSet;

public class Solution {
    public int lengthOfLongestSubstring(String s) {
		int len = s.length();
		if (len == 0) return 0;
		HashSet<Character> seen = new HashSet<>();
		int left = 0;
		int max = Integer.MIN_VALUE;
		for (int right = 0; right < len; right++) {
			char c = s.charAt(right);
			if (!seen.contains(c)) {
				seen.add(c);
			} else {
				while (seen.contains(s.charAt(right)) && left <= right) {
					seen.remove(s.charAt(left));
					left += 1;
				}
			}
			int computed_len = right - left + 1;
			max = max < computed_len ? computed_len : max;
		}
		return max;
    }
}
