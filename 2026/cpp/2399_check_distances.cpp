#include <array>
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
  public:
    static int distance(int a, int b) { return b - a - 1; }
    bool checkDistances(string s, vector<int> &distance) {
		unordered_map<char, int> lookup_table = {};
        for (int i = 0; i < s.size(); i++) {
            char c = s[i];
			auto last_seen = lookup_table.find(c);
            if (last_seen != lookup_table.end()) {
                int calculated_distance = Solution::distance(last_seen->second, i);
                int expected_distance = distance[c - 'a'];
                if (expected_distance != calculated_distance) {
                    return false;
                }
            } else {
				lookup_table[c] = i;
            }
        }
        return true;
    }
};

int main() {
    array<int, 26> lookup_table = {};
    for (int i = 0; i < lookup_table.size(); i++) {
        std::cout << lookup_table[i] << ", ";
    }
    std::cout << '\n' << Solution::distance(0, 1) << '\n';
}
