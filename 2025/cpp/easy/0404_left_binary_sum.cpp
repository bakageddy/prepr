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
	int sumOfLeftRight(TreeNode* root) {
		if (root == nullptr) return 0;
		return helper(root -> left);
	}
    int helper(TreeNode* root) {
		if (root == nullptr) return 0;
		if (root -> left != nullptr) return helper(root -> left) + sumOfLeftRight(root -> right);
		return root -> val;
    }
	int sumOfLeftLeaves(TreeNode* root) {
		return helper(root -> left) + sumOfLeftRight(root -> right);
	}
};
