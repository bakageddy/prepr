#include <algorithm>
#include <vector>

using std::vector;

class Solution {
public:
	void backtrack(vector<int>& candidates, int target, int cursor, vector<vector<int>>& answer, vector<int>& temp) {
		if (target == 0 && !temp.empty()) {
			answer.push_back(temp);
			return;
		}

		if (target <= 0) {
			return;
		}

		for (int i = cursor; i < candidates.size(); i++) {
			if (i > cursor && candidates[i] == candidates[i - 1]) {
				continue;
			}

			auto val = candidates[i];
			temp.push_back(val);
			backtrack(candidates, target - val, i + 1, answer, temp);
			temp.pop_back();
		}

		return;
	}

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
		vector<vector<int>> answer = {};
		vector<int> temp = {};
		std::sort(candidates.begin(), candidates.end());
		backtrack(candidates, target, 0, answer, temp);
		return answer;
    }
};
