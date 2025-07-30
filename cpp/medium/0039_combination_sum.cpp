#include <iostream>
#include <set>
#include <vector>

using std::vector;
using std::set;
class Solution {
public:
	void dfs(set<vector<int>>& acc, vector<int>& options, int target, int start, vector<int>& buf) {
		if (target == 0) {
			acc.insert(vector<int>(buf.begin(), buf.end()));
			return;
		}
		for (int i = start; i < options.size(); i++) {
			int elem = options.at(i);
			if (target < elem) continue;
			buf.push_back(elem);
			dfs(acc, options, target - elem, i, buf);
			buf.pop_back();
		}
	}

	vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
		vector<int> buf = {};
		set<vector<int>> seen;
		dfs(seen, candidates, target, 0, buf);
		return vector<vector<int>>(seen.begin(), seen.end());
	}
};

int main(void) {
	vector<int> candis = {2, 3, 6, 7};
	int target = 7;

	Solution sol = {};
	auto ans = sol.combinationSum(candis, target);
	for (auto arr : ans) {
		for (auto elem : arr) {
			std::cout << elem << ' ';
		}
		std::cout << '\n';
	}
}
