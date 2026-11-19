#include <iostream>
#include <vector>

using std::vector;

class Solution {
  public:
    void helper(vector<int> &candidates, int target, int cursor, vector<vector<int>> &answer,
                vector<int> &temp) {
		if (target == 0 && !temp.empty()) {
			answer.push_back(temp);
			return;
		}
		
		if (target < 0) {
			return;
		}

		for (int i = cursor; i < candidates.size(); i++) {
			auto val = candidates[i];
			temp.push_back(val);
			helper(candidates, target - val, i, answer, temp);
			temp.pop_back();
		}
	}
    vector<vector<int>> combinationSum(vector<int> &candidates, int target) {
        vector<vector<int>> answer = {};
		vector<int> temp = {};
        helper(candidates, target, 0, answer, temp);
        return answer;
    }
};

int main(void) {
	vector<int> candidates = {2, 3, 6, 7};
	int target = 7;
	Solution sol = {};
	auto result = sol.combinationSum(candidates, target);
	for (auto& vec : result) {
		for (auto& elem : vec) {
			std::cout << elem << ',' << ' ';
		}
		std::cout << '\n';
	}
	return 0;
}
