public class Solution {
	public static int[] values = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
	public static String[] romans = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};
    public String intToRoman(int num) {
		int i = 0;
		StringBuffer ans = new StringBuffer();
		while (i < values.length && num != 0) {
			if (Solution.values[i] <= num) {
				ans.append(Solution.romans[i]);
				num -= Solution.values[i];
			} else {
				i++;
			}
		}
		return ans.toString();
    }
}
