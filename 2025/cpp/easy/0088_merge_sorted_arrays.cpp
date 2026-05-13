#include <vector>
#include <iostream>
using std::vector;

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
		int i = m - 1;
		int j = n - 1;
		int k = m + n - 1;
		while (j >= 0) {
			if (i >= 0 && nums1[i] > nums2[j]) {
				nums1[k--] = nums1[i--];
			} else {
				nums1[k--] = nums2[j--];
			}
		}
		return;
    }
};

int main(void) {
	int m = 3;
	int n = 3;
	vector<int> a = {1, 2, 3, 0, 0, 0};
	vector<int> b = {2, 5, 6};
	Solution sol = {};
	sol.merge(a, m, b, n);
	std::cout << "Ans: ";
	for (auto i : a) {
		std::cout << i << ' ';
	}
	std::cout << '\n';
	return 0;
}
