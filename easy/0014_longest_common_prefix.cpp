#include <algorithm>
#include <string>
#include <vector>
class Solution {
public:
	std::string longestCommonPrefix(std::vector<std::string>& strs) {
		if (strs.size() == 0) {
			return "";
		}
		if (strs.size() == 1) {
			return strs[0];
		}

		std::string ans {};
		auto min = std::min(strs.begin(), strs.end());
		for (int i = 0; i < min->length(); i++) {
			for (int j = 0; j < strs.size() - 1; j++) {
				if (strs[j][i] == strs[j + 1][i]) {
					continue;
				} else {
					return ans;
				}
			}
			ans += (*min)[i];
		}
		return ans;
	}
};
