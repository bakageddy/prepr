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
    public int minDepth(TreeNode root) {
		if (root == null) return 0;
		return helper(root);
    }

	public int helper(TreeNode root) {
		if (root.left == null && root.right == null) {
			return 1;
		}

		int lDepth = Integer.MAX_VALUE;
		int rDepth = Integer.MAX_VALUE;

		if (root.left != null) lDepth = helper(root.left);
		if (root.right != null) rDepth = helper(root.right);

		return (lDepth > rDepth ? rDepth : lDepth) + 1;
	}
}
