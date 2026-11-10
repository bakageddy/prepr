#include <iostream>
#include <optional>
#include <queue>

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
    std::optional<int> perfectSubtreeSize(TreeNode *root, std::priority_queue<int> &sizes) {
        if (root->left == nullptr && root->right == nullptr) {
            sizes.push(1);
            return std::make_optional(1);
        } else if (root->left == nullptr) {
			auto is_perfect_right = perfectSubtreeSize(root -> right, sizes);
            return std::nullopt;
        } else if (root->right == nullptr) {
			auto is_perfect_left = perfectSubtreeSize(root -> left, sizes);
            return std::nullopt;
        } else {
            auto is_perfect_left = perfectSubtreeSize(root->left, sizes);
            auto is_perfect_right = perfectSubtreeSize(root->right, sizes);
            if (is_perfect_left && is_perfect_right &&
                (is_perfect_left.value() == is_perfect_right.value())) {
                auto size = is_perfect_left.value() + is_perfect_right.value() + 1;
                sizes.push(size);
                return size;
            } else {
                return std::nullopt;
            }
        }
    }

    int kthLargestPerfectSubtree(TreeNode *root, int k) {
        std::priority_queue<int> sizes = {};
        auto result = perfectSubtreeSize(root, sizes);
        if (sizes.size() >= k) {
            for (int i = 1; i < k; i++) {
                sizes.pop();
            }
            return sizes.top();
        }
        return -1;
    }
};

int main(void) {
    Solution sol = {};
    TreeNode node = TreeNode(7);
    TreeNode left = TreeNode(4);
    node.left = &left;
    auto ans = sol.kthLargestPerfectSubtree(&node, 1);
    std::cout << ans << '\n';
    return 0;
}
