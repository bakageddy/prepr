package dev.bakageddy.prepr;

class Solution {
    public String convertToTitle(int columnNumber) {
		char[] lookup_table = {
			'A', 'B', 'C', 'D', 'E',
			'F', 'G', 'H', 'I', 'J',
			'K', 'L', 'M', 'N', 'O',
			'P', 'Q', 'R', 'S', 'T',
			'U', 'V', 'W', 'X', 'Y',
			'Z'
		};

		StringBuffer buffer = new StringBuffer();
		while (columnNumber > 0) {
			columnNumber--;
			buffer.append(lookup_table[columnNumber % 26]);
			columnNumber /= 26;
		}
		return buffer.toString();
    }
}
