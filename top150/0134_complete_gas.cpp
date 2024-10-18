#include <vector>
using std::vector;
class Solution {
public:
	vector<int> min(vector<int>& smth) {
		int min = 0;
		for (int i = 0; i < smth.size(); i++) {
			if (smth[i] < smth[min]) {
				min = i;
			}
		}
		int val = smth[min];
		vector<int> output = {};
		for (int i = 0; i < smth.size(); i++) {
			if (smth[i] == val) {
				output.push_back(i);
			}
		}
		return output;
	}
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
		vector<int> starting = min(cost);
		int len = cost.size();
		for (auto origin : starting) {
			int curr_cap = 0;
			for (int i = 0; i < len; i++) {
				curr_cap += gas[(origin + i) % len];
				curr_cap -= cost[(origin + i) % len];
				if (curr_cap < 0) break;
			}
			if (curr_cap >= 0) return origin;
		}
		return -1;
    }
};
