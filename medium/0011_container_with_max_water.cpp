#include <algorithm>
#include <cstdlib>
#include <limits>
#include <vector>
using std::vector;

class Solution {
public:
	int calculateArea(int a, int b, int distance) {
		return std::min(a, b) * distance;
	}
    int maxArea(vector<int>& height) {
		int len = height.size();
		if (len == 0 || len == 1) return 0;
		int max_area = std::numeric_limits<int>::min();
		int i = 0;
		int j = len - 1;
		while (i <= j) {
			int area = calculateArea(height[i], height[j], j - i);
			if (area > max_area) max_area = area;
			if (height[i] > height[j]) j--;
			else i++;
		}
		return max_area;
    }
};
