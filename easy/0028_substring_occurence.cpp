#include <string>

class Solution {
public:
    int strStr(std::string haystack, std::string needle) {
        if (haystack.size() < needle.size()) return -1;
        int len = needle.size();
        for (int i = 0; i < haystack.size() - len + 1; i++) {
            int j = 0;
            while (j < len) {
                if (needle[j] != haystack[i + j]) {
                    break;
                }
                j++;
            }
            if (j == len) return i;
        }
        return -1;
    }
};
