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
    public int countNodes(TreeNode root) {
		int count = 0;
		if (root == null) return 0;
		if (root.right != null && root.left == null) {
			return countNodes(root.right);
		} else {
			count += countNodes(root.left);
			count += countNodes(root.right);
			return count + 1;
		}
    }
}
