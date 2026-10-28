#include <iostream>
#include <string>
#include <stack>
using namespace std;

class Solution {
public:
    bool backspaceCompare(string s, string t) {
		stack<char> first = {};
		stack<char> second = {};
		for (char c : s) {
			if (c == '#') {
				if (first.empty()) continue;
				first.pop();
			} else {
				first.push(c);
			}
		}

		for (char c : t) {
			if (c == '#') {
				if (second.empty()) continue;
				second.pop();
			} else {
				second.push(c);
			}
		}

		return first == second;
    }
};

int main(void) {
	stack<char> s = {};
	s.push('f');
	stack<char> t = {};
	t.push('f');

	Solution sol = {};
	std::cout << sol.backspaceCompare("a#b", "b") << '\n';
	std::cout << sol.backspaceCompare("y#fo##f", "y#f#o##f") << '\n';
	std::cout << (s == t) << '\n';
	return 0;
}
