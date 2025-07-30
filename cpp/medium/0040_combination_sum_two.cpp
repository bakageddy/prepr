#include <algorithm>
#include <iostream>
#include <set>
#include <string>
#include <vector>

using std::vector;
using std::set;

class Solution {
public:
	void dfs(set<set<int>>& acc, const vector<int>& candidates, set<int>& buf, int target, int idx) {
		if (target == 0) {
			acc.insert(set(buf.begin(), buf.end()));
			return;
		}

		for (int i = idx; i < candidates.size(); i++) {
			int elem = candidates.at(i);
			if (target < elem) break;
			buf.insert(i);
			dfs(acc, candidates, buf, target - elem, idx + 1);
			buf.erase(i);
		}
	}

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
		set<set<int>> seen = {};
		set<int> buf = {};
		std::sort(candidates.begin(), candidates.end());
		dfs(seen, candidates, buf, target, 0);

		vector<vector<int>> ans = {};
		for (auto set : seen) {
			vector<int> temp = {};
			for (auto elem : set) {
				temp.push_back(candidates.at(elem));
			}
			ans.push_back(temp);
		}
		return ans;
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
