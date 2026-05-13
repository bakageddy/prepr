import java.util.HashMap;

public class Solution {
    public boolean isIsomorphic(String s, String t) {
		HashMap<Character, Character> ab = new HashMap<>();
		HashMap<Character, Character> ba = new HashMap<>();
		for (int i = 0; i < s.length(); i++) {
			Character a = s.charAt(i);
			Character b = t.charAt(i);

			if (ab.containsKey(a)) {
				Character c = ab.get(a);
				if (b != c) return false;
			} else {
				ab.put(a, b);
			}

			if (ba.containsKey(b)) {
				Character c = ba.get(b);
				if (c != a) return false;
			} else {
				ba.put(b, a);
			}
		}
		return true;
    }
}
