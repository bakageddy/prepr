#include <iostream>
#include <vector>
#include <string>
using namespace std;
class Solution {
public:
    vector<string> divideString(string s, int k, char fill) {
		vector<string> str = {};
		string temp = {}; 
		for (int i = 0; i < s.size(); i++) {
			if (temp.size() == k) {
				str.push_back(temp);
				temp = "";
			}
			temp += s[i];
		}

		while (temp.size() < k) {
			temp.push_back(fill);
		}

		if (temp.size() != 0) {
			str.push_back(temp);
		}

		return str;
    }
};

int main() {
	Solution sol = {};
	auto result = sol.divideString("abcdefg", 3, 'x');
	for (auto group : result) {
		cout << group << '\n';
	}

	return 0;
}
