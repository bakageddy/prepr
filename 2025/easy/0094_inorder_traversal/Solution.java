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

public class Solution {
    public List<Integer> inorderTraversal(TreeNode root) {
		List<Integer> ans = new ArrayList<>();
		return helper(root, ans);
    }

	public List<Integer> helper(TreeNode root, List<Integer> acc) {
		if (root == null) {
			return acc;
		}
		helper(root.left, acc);
		acc.addLast(root.val);
		helper(root.right, acc);
		return acc;
	}
}
