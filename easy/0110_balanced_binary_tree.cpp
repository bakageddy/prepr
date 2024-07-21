#include <algorithm>
#include <cstdlib>
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
	int height_of_node(TreeNode *root) {
		if (root == nullptr) 
			return 0;

		return 1 + std::max(
			height_of_node(root -> left),
			height_of_node(root -> right)
		);
	}

    bool isBalanced(TreeNode* root) {
		if (root == nullptr) return true;
		int left_height = height_of_node(root -> left);
		int right_height = height_of_node(root -> right);
		return std::abs(left_height - right_height) < 2 && isBalanced(root -> left) && isBalanced(root -> right);
    }
};
