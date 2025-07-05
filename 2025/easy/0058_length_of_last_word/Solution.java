package dev.bakageddy.prepr;
public class Solution {
	public int lengthOfLastWord(String word) {
		int length = word.length();
		int i = length - 1;
		int word_len = 0;
		for (; i >= 0; i--) {
			if (word.charAt(i) != ' ') break;
		}
		for (; i >= 0; i--, word_len++) {
			if (word.charAt(i) == ' ') break;
		}
		return word_len;
	}
}
