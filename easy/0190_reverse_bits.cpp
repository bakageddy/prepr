#include <cstdint>

class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
		uint32_t temp = n;
		uint32_t result = 0;
		int count = 0;
		while (temp != 0) {
			result = result << 1;
			result |= temp & 1;
			temp = temp >> 1;
			count++;
		}
		while (count < 32) {
			result <<= 1;
			count++;
		}
		return result;
    }
};
