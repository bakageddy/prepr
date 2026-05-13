#include <iostream>
#include <string>
#include <vector>

using std::vector, std::string;

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
    vector<string> binaryTreePaths(TreeNode* root) {
		if (root == nullptr) return {};
		if (root -> left == nullptr && root -> right == nullptr) {
			return {std::to_string(root -> val)};
		}
		auto left = binaryTreePaths(root -> left);
		auto right = binaryTreePaths(root -> right);
		left.insert(left.end(), right.begin(), right.end());
		for (auto& x : left) {
			x = std::to_string(root -> val) + "->" + x;
		}
		return left;
    }
};

int main(void) {
	TreeNode root = TreeNode(1);
	TreeNode left = TreeNode(2);
	TreeNode right = TreeNode(3);
	TreeNode leftleft = TreeNode(4);
	root.left = &left;
	left.left = &leftleft;
	root.right = &right;

	Solution sol = {};
	auto ans = sol.binaryTreePaths(&root);
	for (auto& x : ans) {
		std::cout << x << '\n';
	}
	return 0;
}

