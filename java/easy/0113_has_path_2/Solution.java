package dev.bakageddy.prepr;

import java.util.ArrayList;
import java.util.List;

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
	public List<List<Integer>> pathSum(TreeNode root, int targetSum) {
		List<List<Integer>> acc = new ArrayList<>();
		List<Integer> output = new ArrayList<>();
		helper(acc, output, root, targetSum, 0);
		return acc;
	}

	public void helper(
		List<List<Integer>> acc,
		List<Integer> output,
		TreeNode root,
		int targetSum,
		int currentSum
	) {
		if (root == null) return;
		currentSum += root.val;
		output.addLast(root.val);
		if (root.left == null && root.right == null && targetSum == currentSum) {
			acc.add(new ArrayList<>(output));
		}
		helper(acc, output, root.left, targetSum, currentSum);
		helper(acc, output, root.right, targetSum, currentSum);
		output.removeLast();
	}
}
