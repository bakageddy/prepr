class ListNode {
    int val;
    ListNode next;
    ListNode() {}
    ListNode(int val) { this.val = val; }
    ListNode(int val, ListNode next) { this.val = val; this.next = next; }
}

public class Solution {
    public ListNode addTwoNumbers(ListNode l1, ListNode l2) {
		boolean carry = false;
		ListNode result_head = new ListNode(0);
		ListNode ret = result_head;
		while (l1 != null && l2 != null) {
			int sum = l1.val + l2.val;
			if (carry) {
				sum += 1;
			}

			if (sum >= 10) {
				carry = true;
				sum %= 10;
			} else {
				carry = false;
			}

			ListNode temp = new ListNode(sum);
			result_head.next = temp;
			result_head = temp;
			l1 = l1.next;
			l2 = l2.next;
		}

		while (l1 != null) {
			int sum = l1.val;
			if (carry) {
				sum += 1;
			}

			if (sum >= 10) {
				carry = true;
				sum %= 10;
			} else {
				carry = false;
			}
			
			ListNode temp = new ListNode(sum);
			result_head.next = temp;
			result_head = temp;
			l1 = l1.next;
		}

		while (l2 != null) {
			int sum = l2.val;
			if (carry) {
				sum += 1;
			}

			if (sum >= 10) {
				carry = true;
				sum %= 10;
			} else {
				carry = false;
			}

			ListNode temp = new ListNode(sum);
			result_head.next = temp;
			result_head = temp;
			l2 = l2.next;
		}

		if (carry) {
			ListNode temp = new ListNode(1);
			result_head.next = temp;
			result_head = temp;
		}
		return ret.next;
    }
}
