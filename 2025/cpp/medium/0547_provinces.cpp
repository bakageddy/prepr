#include <vector>
#include <unordered_set>

using std::vector, std::unordered_set;

class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
		unordered_set<int> visited = {};
		int ans = 0;
		dfs(isConnected, visited, 1, ans);
		return ans;
    }
	void dfs(vector<vector<int>>& graph, unordered_set<int> visited, int start, int& provinces) {
		visited.insert(start);
		for (auto x : graph[start]) {
			if (visited.find(x) == visited.end()) {
				provinces++;
				dfs(graph, visited, x, provinces);
			}
		}
	}
};
