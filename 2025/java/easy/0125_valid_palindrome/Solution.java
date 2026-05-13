package dev.bakageddy.prepr;

public class Solution {
    public boolean isPalindrome(String s) {
		// NOTE: I am dumb
		if (s.isEmpty()) return false;
		if (s.isBlank()) return true;
		int i = 0;
		int j = s.length() - 1;
		while (i <= j) {
			char a = s.charAt(i);
			char b = s.charAt(j);
			if (Character.isDigit(a) || Character.isDigit(b)) return false;
			if (!Character.isAlphabetic(a)) {
				i++;
				continue;
			} else if (!Character.isAlphabetic(b)) {
				j--;
				continue;
			} else {
				if (Character.toLowerCase(a) != Character.toLowerCase(b)) {
					return false;
				}
				i++;
				j--;
			}
		}
		return true;
    }
}
