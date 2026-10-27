#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
	static void reverse_string(string& s, const int i, const int j) {
		int end = j - 1;
		for (int start = i; start < end; start++, end--) {
			char temp = s[start];
			s[start] = s[end];
			s[end] = temp;
		}
	}
    static string reverseWords(string s) {
		int i = 0;
		while (i < s.size()) {
			int j = i + 1;
			while (j < s.size()) {
				if (s[j] == ' ') {
					break;
				} else {
					j += 1;
				}
			}
			reverse_string(s, i, j);
			i = j + 1;
		}
		return s;
    }
};

int main(void) {
	string name = "dinesh kumar";
	// no-op
	string last = "kumar";
	Solution::reverse_string(last, 0, last.size());
	cout << last << '\n';
	cout << Solution::reverseWords(name) << '\n';
	return 0;
}
