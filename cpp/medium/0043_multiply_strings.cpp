#include <iostream>
#include <string>
using std::string;

class Solution {
public:
    string multiply(string num1, string num2) {
		if (num1.compare("0") == 0 || num2.compare("0") == 0) return "0";
		string ans = string();
		for (int i = num2.size() - 1; i >= 0; i--) {
			char num = num2.at(i);
			ans = add_string(ans, multiply_char(num1, num));
			ans.push_back('0');
		}
		return ans;
    }

	string multiply_char(string& num1, char num2) {
		if (num2 == '0') return "";
		int carry = 0;
		string ans = {};
		for (int i = num1.size() - 1; i >= 0; i--) {
			char num = num1.at(i);
			int prod = (num2 - '0') * (num - '0');
			prod += carry;

			ans = (char) (prod % 10 + '0') + ans;
			carry = prod / 10;
		}
		if (carry != 0) {
			ans = (char) (carry + '0') + ans;
		}
		return ans;
	}

	string add_string(string& num1, string num2) {
		int carry = 0;
		int i = num1.size() - 1;
		int j = num2.size() - 1;
		string ans = {};
		while (i >= 0 && j >= 0) {
			char c1 = num1.at(i);
			char c2 = num2.at(j);

			int sum = (c1 - '0') + (c2 - '0');
			sum += carry;

			ans = (char)(sum % 10 + '0') + ans;
			carry = sum / 10;

			i--;
			j--;
		}

		while (i >= 0) {
			char c1 = num1.at(i);

			int sum = (c1 - '0') + carry;
			ans = (char)(sum % 10 + '0') + ans;
			carry = sum / 10;

			i--;
		}

		while (j >= 0) {
			char c2 = num2.at(j);

			int sum = (c2 - '0') + carry;
			ans = (char)(sum % 10 + '0') + ans;
			carry = sum / 10;

			j--;
		}

		return ans;
	}
};

int main(void) {
	Solution sol = {};
	std::cout << sol.multiply("12", "30") << '\n';
}
