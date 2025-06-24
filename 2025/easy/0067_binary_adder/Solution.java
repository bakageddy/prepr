public class Solution {
	public String addBinary(String a, String b) {
		int alen = a.length();
		int blen = b.length();
		int max_len = alen > blen ? alen : blen;
		a = normalize_binary(a, max_len);
		b = normalize_binary(b, max_len);

		StringBuffer buf = new StringBuffer(max_len + 1);
		boolean overflow = false;
		for (int i = max_len - 1; i >= 0; i++) {
			char res;
			// if (overflow) {
			// 	if (a.charAt(i) == '1' && b.charAt(i) == '1') {
			// 		overflow = true;
			// 		res = '1';
			// 	} else if (a.charAt(i) == '1' || b.charAt(i) == '1') {
			// 		overflow = false;
			// 		res = '0';
			// 	} else {
			// 		overflow = false;
			// 		res = '1';
			// 	}
			// } else {
			// 	if (a.charAt(i) == '1' && b.charAt(i) == '1') {
			// 		overflow = true;
			// 		res = '0';
			// 	} else if (a.charAt(i) == '1' || b.charAt(i) == '1') {
			// 		overflow = false;
			// 		res = '1';
			// 	} else {
			// 		overflow = false;
			// 		res = '0';
			// 	}
			// }

			if (a.charAt(i) == '1' && b.charAt(i) == '1') {
				res = overflow ? '1' : '0';
				overflow = true;
			} else if (a.charAt(i) == '1' || b.charAt(i) == '1') {
				res = overflow ? '0' : '1';
			} else {
				res = overflow ? '1' : '0';
				overflow = false;
			}
			buf.insert(0, res);
		}

		if (overflow) {
			buf.insert(0, '1');
		} else {
			buf.delete(0, 1);
		}

		return buf.toString();
	}

	public String normalize_binary(String x, int target_length) {
		assert(target_length >= x.length());
		StringBuffer buf = new StringBuffer(x);
		for (int i = 0; i < (target_length - x.length()); i++) {
			buf.insert(0, '0');
		}
		return buf.toString();
	}
}
