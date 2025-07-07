#include <iostream>
#include <vector>

using std::vector;

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
		vector<vector<int>> ans = {};
		if (numRows == 1) {
			ans.push_back({1});
		} else if (numRows == 2) {
			ans.push_back({1});
			ans.push_back({1, 1});
		} else {
			ans.push_back({1});
			ans.push_back({1, 1});
			for (int i = 2; i < numRows; i++) {
				vector<int> row = {1};
				for (int j = 1; j < i; j++) {
					row.push_back(ans[i - 1][j - 1] + ans[i - 1][j]);
				}
				row.push_back(1);
				ans.push_back(row);
			}
		}
		return ans;
    }
};

int main(void) {
	Solution sol = {};
	auto ans = sol.generate(4);
	for (auto& row : ans) {
		for (auto& i : row) {
			std::cout << i << " ";
		}
		std::cout << '\n';
	}
	return 0;
}
