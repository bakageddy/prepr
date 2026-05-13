#include <vector>
#include <algorithm>
#include <iostream>

using std::vector;

class Solution {
public:
	int binary_search(const vector<int> haystack, const int needle) {
		int low = 0;
		int high = haystack.size() - 1;
		while (low <= high) {
			int mid = low + (high - low) / 2;
			if (haystack[mid] == needle) return mid;
			else if (haystack[mid] > needle) high = mid - 1;
			else if (haystack[mid] < needle) low = mid + 1;
		}
		return -1;
	}
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
		std::sort(nums1.begin(), nums1.end());
		std::sort(nums2.begin(), nums2.end());
		vector<int> ans = {};
		int prev_value = 1001;
		for (int i = 0; i < nums1.size(); i++) {
			if (prev_value == nums1[i]) continue;
			int idx = binary_search(nums2, nums1[i]);
			if (idx != -1) ans.push_back(nums1[i]);
			prev_value = nums1[i];
		}
		return ans;
    }
};

int main(void) {
	Solution sol = {};
	vector<int> ans = {1, 2, 3, 4, 5, 6};
	std::cout << sol.binary_search(ans, 6) << '\n';
	return 0;
}
