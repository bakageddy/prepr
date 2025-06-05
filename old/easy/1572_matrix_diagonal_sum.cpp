#include <cassert>
#include <vector>

using std::vector;

class Solution {
public:
	int diagonalSum(vector<vector<int>>& mat) {
		int rows = mat.size();
		int cols = mat[0].size();
		int sum = 0;
		for (int i = 0; i < rows; i++) {
			sum += mat[i][i];
			if (i == rows - 1 - i) continue;
			sum += mat[i][rows - 1 - i];
		}
		return sum;
	}
};

int main(void) {
	vector<vector<int>> matrix = {
	{1, 2, 3},
	{4, 5, 6},
	{7, 8, 9},
	};
	Solution sol = {};
	int sum = sol.diagonalSum(matrix);
	assert(sum == 25);
	return 0;
}
