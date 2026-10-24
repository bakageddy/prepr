#include <vector>
#include <string>

using namespace std;
class Solution {
public:
    vector<int> findWordsContaining(vector<string>& words, char x) {
		// TODO: learn enough arm64 SIMD and x86 SIMD instructions
		// to vectorize the inner loop
		// TODO: Do it in zig and rust
		// NOTE: word is guarnteed to be of max 50 chars
		// We can load in 50 chars or whatever the length of the word is
		// in a AVX512 machine in a single instruction and then splat a vector
		// of the given char then we can compare it, we can skip the current word
		// if it's 0 (not found) else if it's greater than 0 (found) we can push
		// the result into the vector
		vector<int> result = {};
		for (int i = 0; i < words.size(); i++) {
			for (char c : words[i]) { if (c == x) {
					result.push_back(i);
					break;
				}
			}
		}
		return result;
    }
};
