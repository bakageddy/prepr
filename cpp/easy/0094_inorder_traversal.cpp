
#include <optional>
#include <vector>

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
	std::vector<int> inorderTraversal(TreeNode* root) {
		std::vector<int> ans;
		inorder_helper(root, ans);
		return ans;
    }
	void inorder_helper(TreeNode *root, std::vector<int>& vals) {
		if (root == nullptr) return;
		inorder_helper(root -> left, vals);
		vals.push_back(root -> val);
		inorder_helper(root -> right, vals);
	}
};
