package dev.bakageddy.prepr;

import java.util.HashMap;
import java.util.PriorityQueue;

public class Solution {
    public int minDeletion(String s, int k) {
		HashMap<Character, Integer> map = new HashMap<>();
		for (int i = 0; i < s.length(); i++) {
			char c = s.charAt(i);
			map.computeIfPresent(c, (_ch, n) -> { return n++;} );
			map.putIfAbsent(c, 0);
		}

		int distinct_characters = map.size();
		if (map.size() <= k) return 0;

		// You don't even need to do this, just sum the map.values() and return the minimum of (map.size() - k)
		PriorityQueue<Integer> queue = new PriorityQueue<>(map.values());
		int output = 0;
		for (int i = 0; i < (distinct_characters - k); i++) {
			output += queue.poll();
		}

		return output;
    }
}
