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
    bool isSymmetric(TreeNode* root) {
		return is_symmetric_helper(root -> left, root -> right);
    }
	bool is_symmetric_helper(TreeNode *left, TreeNode *right) {
		if (left == nullptr && right == nullptr) return true;
		if (!left || !right) return false;
		if (left -> val == right -> val) {
			return true 
				&& is_symmetric_helper(left -> right, right -> left)
				&& is_symmetric_helper(left -> left, right -> right);
		}
		return false;
	}
};
