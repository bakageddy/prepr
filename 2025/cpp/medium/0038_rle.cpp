#include <iostream>
#include <string>
using std::string;

class Solution {
public:
    string countAndSay(int n) {
		if (n == 1) {
			return "1";
		} else {
			return rle(countAndSay(n - 1));
		}
    }

	static string rle(string s) {
		string ans = string();
		char prev = s.at(0); // something that is not input;
		int count = 0;
		for (int i = 0; i < s.length(); i++) {
			char curr = s.at(i);
			if (curr != prev) {
				ans += std::to_string(count);
				ans += prev;
				prev = curr;
				count = 1;
			} else {
				count += 1;
			}
		}
		if (count != 0) {
			ans += std::to_string(count);
			ans += prev;
		}
		return ans;
	}
};

int main(void) {
	std::cout << Solution::rle("1211") << '\n';
	return 0;
}
