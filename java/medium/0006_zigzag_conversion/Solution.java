import java.util.ArrayList;
import java.util.List;

public class Solution {
    public String convert(String s, int numRows) {
		List<StringBuffer> zigzag = new ArrayList<>(numRows);
		for (int i = 0; i < numRows; i++) {
			zigzag.add(new StringBuffer());
		}

		StringBuffer result = new StringBuffer(s.length());
		int idx = 0;
		int zigzag_idx = 0;
		int direction = 1;
		while (idx < s.length()) {
			char c = s.charAt(idx);
			zigzag.get(zigzag_idx).append(c);

			zigzag_idx += direction;
			if (zigzag_idx == numRows) {
				direction = -1;
			} else if (zigzag_idx == 0) {
				direction = 1;
			}
			idx++;
		}

		for (int i = 0; i < numRows; i++) {
			result.append(zigzag.get(i));
		}

		return result.toString();
    }
}
