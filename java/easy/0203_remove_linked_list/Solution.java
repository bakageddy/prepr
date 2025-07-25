package dev.bakageddy.prepr;

class ListNode {
	int val;
	ListNode next;

	ListNode() {
	}

	ListNode(int val) {
		this.val = val;
	}

	ListNode(int val, ListNode next) {
		this.val = val;
		this.next = next;
	}
}

public class Solution {
	public ListNode removeElements(ListNode head, int val) {
		return helper(head, val);
	}

	private ListNode helper(ListNode head, int val) {
		if (head == null) return null;
		if (head.val == val) {
			return helper(head.next, val);
		} else {
			head.next = helper(head.next, val);
			return head;
		}
	}
}
