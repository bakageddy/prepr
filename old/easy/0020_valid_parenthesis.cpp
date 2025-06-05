#include <string>
#include <stack>

class Solution {
public:
	bool isValid(std::string s) {
		std::stack<char> stack {};
		for (auto i : s) {
			switch (i) {
			case '(':
			case '{':
			case '[':
				stack.push(i);
				break;
			case ')': {
				if (!stack.empty() && stack.top() == '(') stack.pop();
				else return false;
			}; break;
			case '}': {
				if (!stack.empty() && stack.top() == '}') stack.pop();
				else return false;
			}; break;
			case ']': {
				if (!stack.empty() && stack.top() == ']') stack.pop();
				else return false;
			}; break;
			}
		}
		return stack.empty();
	}
};

// class Solution {
// public:
// 	bool isValid(std::string s) {
// 		int braces = 0;
// 		int squares = 0;
// 		int parens = 0;
// 		for (auto i : s) {
// 			switch (i) {
// 			case '(': {
// 				parens++;
// 			}; break;
// 			case '{': {
// 				braces++;
// 			}; break;
// 			case '[': {
// 				squares++;
// 			}; break;
// 			case ')': {
// 				parens--;
// 			}; break;
// 			case '}': {
// 				braces--;
// 			}; break;
// 			case ']': {
// 				squares--;
// 			}; break;
// 			}
// 			if (parens < 0 || braces < 0 || squares < 0) {
// 				return false;
// 			}
// 		}
// 		return (parens == 0 && braces == 0 && squares == 0);
// 	}
// };
