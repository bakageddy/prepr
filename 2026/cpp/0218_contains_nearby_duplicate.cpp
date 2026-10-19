#include <bits/stdc++.h>
#include <cstdlib>
#include <unordered_map>
using namespace std;

class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
		unordered_map<int, int> map = {};
		for (int i = 0; i < nums.size(); i++) {
			if (map.find(nums[i]) == map.end()) {
				map[nums[i]] = i;
			} else {
				auto j = map.at(nums[i]);
				if (abs(j - i) <= k) {
					return true;
				} else {
					map[nums[i]] = i;
				}
			}
		}
		return false;
    }
};
