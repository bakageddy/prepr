class Solution {
public:
    bool isPalindrome(int x) {
		if (x < 0) return false;
		if (x == 0) return true;
		long rev = 0;
		long num = x;
		while (num > 0) {
			int rem = num % 10;
			rev *= 10;
			rev += rem;
			num /= 10;
		}
		return rev == x;
    }
};
