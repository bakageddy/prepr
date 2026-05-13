#include <iostream>
#include <vector>
using std::vector;

class Solution {
	public:
	void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
		int i = m - 1;
		int j = n - 1;
		int k = m + n - 1;
		while (i >= 0 && j >= 0) {
			if (nums1[i] > nums2[j]) {
				nums1[k--] = nums1[i--];
			} else {
				nums1[k--] = nums2[j--];
			}
		}
		while (i >= 0) {
			nums1[k--] = nums1[i--];
		}
		while (j >= 0) {
			nums1[k--] = nums2[j--];
		}
	}
};

int main(void) {
	vector<int> x = {1, 2, 3, 4, 0, 0, 0};
	vector<int> y = {2, 3, 4};
	Solution sol = {};
	sol.merge(x, 4, y, 3);
	for (auto i : x) {
		std::cout << i << ' ';
	}
	std::cout << '\n';
	return 0;
}
