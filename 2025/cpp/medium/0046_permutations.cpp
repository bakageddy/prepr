#include <iostream>
#include <unordered_set>
#include <vector>
using std::vector;
class Solution {
	// You don't need a set to do this
	// have a array with index i = true for seen
	void backtrack(const vector<int> original, vector<int>& buffer, vector<vector<int>>& result, std::unordered_set<int> seen) {
		if (original.size() == buffer.size()) {
			result.push_back(buffer);
			return;
		} else {
			for (int i = 0; i < original.size(); i++) {
				if (seen.find(i) != seen.end()) continue;
				buffer.push_back(original[i]);
				seen.insert(i);
				backtrack(original, buffer, result, seen);
				seen.erase(i);
				buffer.pop_back();
			}
		}
	}
public:
	vector<vector<int>> permute(vector<int>& nums) {
		vector<int> buffer = {};
		vector<vector<int>> result = {};
		std::unordered_set<int> seen = {};
		backtrack(nums, buffer, result, seen);
		return result;
	}
};

int main(int argc, char *argv[]) {
	Solution sol = {};
	vector<int> nums = {1, 2, 3};
	auto result = sol.permute(nums);
	for (auto vec : result) {
		for (auto elem : vec) {
			std::cout << elem << ' ';
		}
		std::cout << '\n';
	}
	return 0;
}
