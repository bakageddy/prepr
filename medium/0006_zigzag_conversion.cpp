#include <iostream>
#include <string>
#include <vector>
using std::string, std::vector;

class Solution {
public:
    string convert(string s, int numRows) {
		if (numRows == 1) return s;
		vector<string> holder = {};
		for (int i = 0; i < numRows; i++)
			holder.push_back(string(""));
		string ans = {};
		int change = 0;
		int d = 0;
		for (int i = 0; i < s.size(); i++) {
			if (change == 0) d = 1;
			else if (change == numRows - 1) d = -1;
			holder[change] += s[i];
			change += d;
		}
		for (auto& x : holder) {
			ans.append(x);
		}
		return ans;
    }
};

int main(void) {
	Solution sol = {};
	std::cout << sol.convert("abcdef", 3) << '\n';
	return 0;
}
