#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    int minimumPartition(string s, int k) {
		long long temp = 0;
		int count = 0;
		for (int i = 0; i < s.size(); i++) {
			int val = s[i] - '0';
			if (val > k) {
				return -1;
			}

			if (temp * 10 + val > k) {
				count += 1;
				temp = 0;
			} else {
				temp *= 10;
			}
			temp += val;
		}
		return count + 1;
    }
};

int main() {
	Solution sol = {};
	cout << sol.minimumPartition("238183", 5) << '\n';
	cout << sol.minimumPartition("165462", 60) << '\n';
	return 0;
}
