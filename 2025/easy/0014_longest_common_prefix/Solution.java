public class Solution {
	public String find_minimum_string(String[] strings) {
		int min = strings[0].length();
		String return_value = strings[0];
		for (int i = 0; i < strings.length; i++) {
			if (strings[i].length() <= min) {
				min = strings[i].length();
				return_value = strings[i];
			}
		}

		return return_value;
	}

    public String longestCommonPrefix(String[] strs) {
		String smallest_string = find_minimum_string(strs);
		StringBuilder builder = new StringBuilder();
		for (int i = 0; i < smallest_string.length(); i++) {
			char c = smallest_string.charAt(i);
			for (int j = 0; j < strs.length; j++) {
				if (strs[j].charAt(i) != c) {
					return builder.toString();
				}
			}
			builder.append(c);
		}
		return builder.toString();
    }

	public static void main(String[] args) {
		String[] strings = {"flower", "flow", "flight"};
		String s = new Solution().longestCommonPrefix(strings);
		System.out.println(s);
	}
}
