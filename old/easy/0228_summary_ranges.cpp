#include <cstdlib>
#include <sstream>
#include <string>
#include <vector>

using std::vector, std::string;

class Solution {
public:
	string get_format_string(int start, int stop) {
		std::stringstream temp = {};
		if (start == stop) {
			temp << start;
		} else {
			temp << start << "->" << stop;
		}
		return temp.str();
	}
    vector<string> summaryRanges(vector<int>& nums) {
        if (nums.size() == 0) return {};
		int prev_val = nums[0];
		int start = prev_val, stop = prev_val;
		vector<string> result = {};
		for (int i = 1; i < nums.size(); i++) {
			if (nums[i] == prev_val + 1) {
				stop = nums[i];
			} else {
				string ans = get_format_string(start, stop);
				result.push_back(ans);
				start = nums[i];
				stop = nums[i];
			}
			prev_val = nums[i];
		}
        string ans = get_format_string(start, stop);
        result.push_back(ans);
		return result;
    }
};
