import java.util.ArrayList;
import java.util.List;
import java.util.Stack;

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
	// NOTE: Recursive Solution.
    public List<Integer> preorderTraversal(TreeNode root) {
		List<Integer> acc = new ArrayList<>();
		helper(acc, root);
		return acc;
    }

	private void helper(List<Integer> acc, TreeNode root) {
		if (root == null) {
			return;
		}

		acc.addLast(root.val);
		helper(acc, root.left);
		helper(acc, root.right);
	}

	// NOTE: Iterative Solution
	public List<Integer> preorderTraversal(TreeNode root, boolean iterative) {
		List<Integer> acc = new ArrayList<>();
		Stack<TreeNode> stk = new Stack<>();
		stk.push(root);
		while (!stk.isEmpty()) {
			TreeNode node = stk.pop();
			acc.addLast(node.val);

			if (node.left != null) {
				stk.push(node.left);
			}

			if (node.right != null) {
				stk.push(node.right);
			}
		}
		return acc; 
	}
}
