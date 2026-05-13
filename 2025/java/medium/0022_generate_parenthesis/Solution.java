import java.util.List;
import java.util.ArrayList;

public class Solution {
    public List<String> generateParenthesis(int n) {
		List<String> acc = new ArrayList<>();
		StringBuffer sb = new StringBuffer();
		dfs(acc, sb, 0, 0, n);
		return acc;
    }

	private void dfs(
		List<String> acc,
		StringBuffer output,
		int open,
		int close,
		int levels
	) {
		if (open + close == (2 * levels)) {
			acc.add(output.toString());
			return;
		}
		if (open != levels) {
			output.append('(');
			dfs(acc, output, open + 1, close, levels);
			output.deleteCharAt(output.length() - 1);
		}
		if (close < open) {
			output.append(')');
			dfs(acc, output, open, close + 1, levels);
			output.deleteCharAt(output.length() - 1);
		}
	}
}
