package dev.bakageddy.prepr;

import java.util.HashMap;

public class Solution {
    public boolean isAnagram(String s, String t) {
		if (s.length() != t.length()) return false;
		int[] counter = new int[26];
		for (int i = 0; i < s.length(); i++) {
			char c = s.charAt(i);
			char d = t.charAt(i);
			counter[c - 'a']++;
			counter[d - 'a']--;
		}
		for (int i = 0; i < counter.length; i++) {
			if (counter[i] != 0) { 
				return false;
			}
		}
		return true;
    }
}

