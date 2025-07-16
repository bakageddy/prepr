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
	public List<String> binaryTreePaths(TreeNode root) {
		List<List<Integer>> acc = new ArrayList<>();
		if (root == null) return new ArrayList<>();

		helper(root, acc, new ArrayList<>());
		return flatten(acc);
	}

	private static List<String> flatten(List<List<Integer>> acc) {
		List<String> output = new ArrayList<>();
		for (List<Integer> list : acc) {
			StringBuffer s = new StringBuffer();
			int len = list.size();
			for (int i = 0; i < len - 1; i++) {
				s.append(list.get(i))
					.append("->");
			}
			s.append(list.get(len - 1));
			output.addLast(s.toString());
		}
		return output;
	}

	public void helper(TreeNode root, List<List<Integer>> acc, List<Integer> output) {
		if (root == null) return; 
		if (root.left == null && root.right == null) {
			output.addLast(root.val);
			acc.add(new ArrayList<>(output));
			output.removeLast();
			return;
		}

		output.addLast(root.val);
		helper(root.left, acc, output);
		helper(root.right, acc, output);
		output.removeLast();
	}
}
