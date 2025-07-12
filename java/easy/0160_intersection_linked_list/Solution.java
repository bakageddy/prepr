package dev.bakageddy.prepr;

import java.util.HashSet;

class ListNode {
	int val;
	ListNode next;

	ListNode(int x) {
		val = x;
		next = null;
	}
}

public class Solution {
	public ListNode getIntersectionNode(ListNode headA, ListNode headB) {
		HashSet<ListNode> seen = new HashSet<>();
		for (ListNode temp = headA; temp != null; temp = temp.next) {
			seen.add(temp);
		}
		for (ListNode temp = headB; temp != null; temp = temp.next) {
			if (seen.contains(temp)) {
				return temp;
			}
		}
		return null;
	}
}
