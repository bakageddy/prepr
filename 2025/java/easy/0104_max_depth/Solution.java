package dev.bakageddy.prepr;
class TreeNode {
    int val;
    TreeNode left;
    TreeNode right;
    TreeNode() {}
    TreeNode(int val) { this.val = val; }
    TreeNode(int val, TreeNode left, TreeNode right) {
        this.val = val;
        this.left = left;
        this.right = right;
    }
}

public class Solution {
    public int maxDepth(TreeNode root) {
		if (root == null) return 0;
		int lDepth = 1 + maxDepth(root.left);
		int rDepth = 1 + maxDepth(root.right);
		return lDepth > rDepth ? lDepth : rDepth;
    }
}
