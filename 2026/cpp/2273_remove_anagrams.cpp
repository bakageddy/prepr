#include <array>
#include <iostream>
#include <string>
#include <vector>

using std::array;
using std::string;
using std::vector;

struct Bag {
    array<char, 26> arr;
    static Bag create(const string &str) {
        Bag bag = {};
        for (int i = 0; i < str.size(); i++) {
            bag.arr[str[i] - 'a'] += 1;
        }
        return bag;
    }

    bool operator==(const Bag &b) {
        for (int i = 0; i < b.arr.size(); i++) {
            if (this->arr[i] != b.arr[i]) {
                return false;
            }
        }
        return true;
    }
	
	bool operator!=(const Bag &b) {
        for (int i = 0; i < b.arr.size(); i++) {
            if (this->arr[i] != b.arr[i]) {
                return true;
            }
        }
        return false;
	}
};

class Solution {
  public:
    vector<string> removeAnagrams(vector<string> &words) {
        vector<string> result = {};
        int i = 0;
        while (i < words.size()) {
            Bag haystack = Bag::create(words[i]);
            int j = i;
            while (j < words.size()) {
                Bag needle = Bag::create(words[j]);
                if (needle != haystack) {
					break;
                }
				j += 1;
            }
			result.push_back(words[i]);
			i = j;
        }
        return result;
    }
};

int main(void) {
    Solution sol = {};
    std::vector<string> words = {"abab", "abba", "aabb", "bcb", "cbb", "ab"};
    auto result = sol.removeAnagrams(words);
    for (string word : result) {
        std::cout << word << '\n';
    }
    return 0;
}
