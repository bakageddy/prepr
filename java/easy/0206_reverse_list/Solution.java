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
	public ListNode reverseList(ListNode head) {
		if (head == null) return null;
		ListNode prev = null;
		ListNode trav = head;
		ListNode next = null;
		while (trav != null) {
			next = trav.next;
			trav.next = prev;
			prev = trav;
			trav = next;
		}
		return prev;
	}
}
