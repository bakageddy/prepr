#include <algorithm>
#include <iostream>
#include <vector>

using std::vector;

class Solution {
public:
	void dfs(vector<vector<int>>& acc, vector<int>& candidates, vector<int>& buf, int i, int target) {
		if (target < 0) {
			return;
		}
		if (target == 0) {
			acc.push_back(vector<int>(buf.begin(), buf.end()));
			return;
		}

		if (i < candidates.size()) {
			int elem = candidates[i];
			if (target < elem) return;
			buf.push_back(elem);
			dfs(acc, candidates, buf, i + 1, target - elem);
			buf.pop_back();
			while (i < candidates.size() && i > 0
				&& candidates[i - 1] == candidates[i]) {
				i++;
			}

			dfs(acc, candidates, buf, i + 1, target);

		}
	}

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
		std::sort(candidates.begin(), candidates.end());
		vector<vector<int>> acc = {};
		vector<int> buf = {};
		dfs(acc, candidates, buf, 0, target);
		return acc;
    }
};

int main(void) {
	Solution sol = {};
	vector<int> nums = {10, 1, 2, 7, 6, 1, 5};
	auto ans = sol.combinationSum2(nums, 8);
	for (auto arr : ans) {
		for (auto elem : arr) {
			std::cout << elem << ' ';
		}
		std::cout << '\n';
	}
	return 0;
}
