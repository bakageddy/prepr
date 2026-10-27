#include <algorithm>
#include <iostream>
#include <string>

using namespace std;

class Solution {
  public:
    int maxPower(string s) {
        int frequency = 0;
        int max_frequency = 0;
        char last_seen = '\0';
        for (char c : s) {
            if (c != last_seen) {
                max_frequency = std::max(frequency, max_frequency);
                frequency = 1;
                last_seen = c;
            } else {
                frequency += 1;
            }
        }
        return std::max(frequency, max_frequency);
    }
};

int main(void) {
    Solution sol = {};
    int result = sol.maxPower("cccaaaaabbaa");
    cout << "Max Power of: " << result << '\n';

    int result2 = sol.maxPower("cc");
    cout << "Max Power of: " << result2 << '\n';

    int result3 = sol.maxPower("c");
    cout << "Max Power of: " << result3 << '\n';
	return 0;
}
