package dev.bakageddy.prepr;

class TreeNode {
	int val;
	TreeNode left;
	TreeNode right;

	TreeNode() {
	}

	TreeNode(int val) {
		this.val = val;
	}

	TreeNode(int val, TreeNode left, TreeNode right) {
		this.val = val;
		this.left = left;
		this.right = right;
	}
}

public class Solution {
	public boolean hasPathSum(TreeNode root, int targetSum) {
		if (root == null) {
			return false;
		} else {
			return helper(root, targetSum);
		}
	}

	public boolean helper(TreeNode root, int targetSum) {
		if (root == null) return true;
		return helper(root.left, targetSum - root.val)
			|| helper(root.right, targetSum - root.val);
	}
}
