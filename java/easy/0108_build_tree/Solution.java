package dev.bakageddy.prepr;
class TreeNode {
    public int val;
    public TreeNode left;
    public TreeNode right;
    public TreeNode() {}
    public TreeNode(int val) { this.val = val; }
    public TreeNode(int val, TreeNode left, TreeNode right) {
        this.val = val;
        this.left = left;
        this.right = right;
    }
}

public class Solution {
    public TreeNode sortedArrayToBST(int[] nums) {
		if (nums.length == 0) return null;
		return helper(nums, 0, nums.length - 1);
    }

	public TreeNode helper(int[] nums, int start, int end) {
		if (start > end) return null;
		int mid = start + (end - start) / 2;
		TreeNode root = new TreeNode(nums[mid]);
		root.left = helper(nums, start, mid - 1);
		root.right = helper(nums, mid + 1, end);
		return root;
	}
}
