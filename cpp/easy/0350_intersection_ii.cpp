#include <algorithm>
#include <vector>
#include <unordered_map>

using std::sort, std::vector, std::unordered_map;

class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
		if (nums1.size() > nums2.size()) return intersect(nums2, nums1);
		unordered_map<int, int> count_table = {};
		vector<int> ans = {};
		for (int i = 0; i < nums1.size(); i++) {
			auto found = count_table.find(nums1[i]);
			if (found == count_table.end()) {
				count_table[nums1[i]] = 1;
			} else {
				count_table[nums1[i]] += 1;
			}
		}

		for (int i = 0; i < nums2.size(); i++) {
			auto found = count_table.find(nums2[i]);
			if (found != count_table.end() && found -> second != 0) {
				ans.push_back(nums2[i]);
				count_table[nums2[i]] -= 1;
			}
		}

		return ans;
    }
};

// Optimized
class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
		sort(nums1.begin(), nums1.end());
		sort(nums2.begin(), nums2.end());
		int i = 0;
		int j = 0;
		vector<int> ans = {};
		while (i < nums1.size() && j < nums2.size()) {
			if (nums1[i] == nums2[j]) {
				ans.push_back(nums1[i]);
				i++;
				j++;
			} else if (nums1[i] > nums2[j]) {
				j++;
			} else {
				i++;
			}
		}
		return ans;
    }
};
