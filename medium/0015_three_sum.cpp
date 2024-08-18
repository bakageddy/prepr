#include <algorithm>
#include <unordered_set>
#include <vector>
using std::vector;
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
		std::sort(nums.begin(), nums.end());
		vector<vector<int>> ans = {};
		for (int i = 0; i < nums.size() - 3; i++) {
			int j = i + 1;
			int k = nums.size() - 1;
			while (j < k) {
				int sum = nums[j] + nums[k];
				if (sum == -nums[i]) {
					ans.push_back({nums[i], nums[j], nums[k]});
					j++;
					k--;
				} else if (sum > -nums[i]) {
					k--;
				} else {
					j++;
				}
			}
		}
		return ans;
    }
};
