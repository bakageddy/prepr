#include <iostream>
#include <string>

class Solution {
public:
	std::string addBinary(std::string a, std::string b) {
		int len_a = a.length();
		int len_b = b.length();
		if (len_a == 0) return b;
		if (len_b == 0) return a;
		if (a.length() > b.length()) {
			return addBinary(b, a);
		}

		bool carry = false;
		std::string ans = "";
		std::string temp_a = "";

		for (int i = 0; i < len_a; i++) {
			temp_a.push_back(a[i]);
		}
		for (int i = 0; i < len_b - len_a; i++) {
			temp_a.insert(temp_a.begin(), '0');
		}

		char result {};

		for (int i = len_b - 1; i >= 0; i--) {
			if (temp_a[i] == '0' && b[i] == '0') {
				result = '0';
				if (carry) {
					result = '1';
					carry = false;
				}
				ans.insert(ans.begin(), result);
			} else if (temp_a[i] == '0' && b[i] == '1') {
				result = '1';
				if (carry) {
					result = '0';
					carry = true;
				}
				ans.insert(ans.begin(), result);
			} else if (temp_a[i] == '1' && b[i] == '0') {
				result = '1';
				if (carry) {
					result = '0';
					carry = true;
				}
				ans.insert(ans.begin(), result);
			} else if (temp_a[i] == '1' && b[i] == '1') {
				result = '0';
				if (carry) {
					result = '1';
				}
				carry = true;
				ans.insert(ans.begin(), result);
			}
		}

		if (carry) {
			ans.insert(ans.begin(), '1');
		}
		return ans;
    }
};


int main(void) {
	Solution sol = {};
	std::string a = {};
	std::string b = {};

	std::cin >> a;
	std::cin >> b;

	std::string ans = sol.addBinary(a, b);
	std::cout << "Ans: " << ans << '\n';
	
	return 0;
}
