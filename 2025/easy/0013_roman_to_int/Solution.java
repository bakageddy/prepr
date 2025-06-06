import java.util.HashMap;

public class Solution {
	public HashMap<Character, Integer> getMap() {
		HashMap<Character, Integer> map = new HashMap<>();
		map.put('M', 1000);
		map.put('D', 500);
		map.put('C', 100);
		map.put('L', 50);
		map.put('X', 10);
		map.put('V', 5);
		map.put('I', 1);
		return map;
	}

	public int romanToInt(String s) {
		int value = 0;
		int prev_value = 0;
		var map = getMap();
		for (int i = s.length() - 1; i >= 0; i--) {
			char c = s.charAt(i);
			int current_value = map.get(c);
			if (prev_value > current_value) {
				value = value - current_value;
			} else {
				value += current_value;
			}
			prev_value = current_value;
		}
		return value;
	}
}
