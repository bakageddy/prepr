import java.util.ArrayList;
import java.util.List;

public class Solution {
	public List<String> letterCombinations(String digits) {
		if (digits.isEmpty()) return new ArrayList<>();
		List<String> acc = new ArrayList<>();
		StringBuffer sb = new StringBuffer();
		String[] lookup = {
				"abc", // 2 - 0
				"def", // 3 - 1
				"ghi", // 4 - 2
				"jkl", // 5 - 3
				"mno", // 6 - 4
				"pqrs",// 7 - 5
				"tuv", // 8 - 6
				"wxyz" // 9 - 7
		};
		dfs(acc, digits, lookup, 0, sb);
		return acc;
	}

	private void dfs(
		List<String> acc,
		String input,
		String[] lookup_table,
		int idx,
		StringBuffer output
	) {
		if (idx == input.length()) {
			acc.addLast(output.toString());
			return;
		}

		char c = input.charAt(idx);
		String phone_string = lookup_table[c - '2'];
		for (int i = 0; i < phone_string.length(); i++) {
			output.append(phone_string.charAt(i));
			dfs(acc, input, lookup_table, idx + 1, output);
			output.deleteCharAt(output.length() - 1);
		}
		return;
	}

	public static void main(String[] args) {
		Solution sol = new Solution();
		var result = sol.letterCombinations("23");
		for (String s : result) {
			System.out.println(s);
		}
	}
}
