package dev.bakageddy.prepr;

import java.util.List;
import java.util.ArrayList;

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

class Solution {
    public List<Integer> postorderTraversal(TreeNode root) {
		List<Integer> acc = new ArrayList<>();
		helper(acc, root);
		return acc;
    }

	private void helper(List<Integer> acc, TreeNode root) {
		if (root == null) return;
		helper(acc, root.left);
		helper(acc, root.right);
		acc.addLast(root.val);
	}
}
