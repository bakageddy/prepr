#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
  public:
    vector<vector<long long>> splitPainting(vector<vector<int>> &segments) {
        std::sort(segments.begin(), segments.end(), [](vector<int> a, vector<int> b) {
            return a[0] > b[0] && a[1] > b[1];
        });
        for (auto &vec : segments) {
        }
        return {};
    }
};

int main(void) {
    vector<vector<int>> segments = {};
    segments.emplace_back(vector{1, 2, 3});
    segments.emplace_back(vector{1, 4, 3});
    Solution sol = {};
    sol.splitPainting(segments);
    return 0;
}
