#include <stack>
#include <vector>
using std::vector;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
	// Recursive
    vector<int> postorderTraversal(TreeNode* root) {
		if (root == nullptr) return {};
		vector<int> result = {};
		auto left = postorderTraversal(root -> left);
		auto right = postorderTraversal(root -> right);
		result.insert(result.end(), left.begin(), left.end());
		result.insert(result.end(), right.begin(), right.end());
		result.push_back(root -> val);
		return result;
    }

	// Iterative
	vector<int> post_order_iterative(TreeNode *root) {
		std::stack<TreeNode *> st = {};
		vector<int> ans = {};
		TreeNode *node = root;
		while (node || !st.empty()) {
			if (node) {
				st.push(node -> left);
				st.push(node -> right);
				ans.push_back(node -> val);
			} else {
				node = st.top();
				st.pop();
			}
		}
		return ans;
	}
};

