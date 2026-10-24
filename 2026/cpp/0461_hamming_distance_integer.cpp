class Solution {
public:
    int hammingDistance(int x, int y) {
        int result = x ^ y;
		// NOTE: Only works on cpp20
		// return std::popcount(result);
		return __builtin_popcount(result);
    }
};
