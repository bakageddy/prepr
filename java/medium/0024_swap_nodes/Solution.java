class ListNode {
    int val;
    ListNode next;
    ListNode() {}
    ListNode(int val) { this.val = val; }
    ListNode(int val, ListNode next) { this.val = val; this.next = next; }
}

public class Solution {
    public ListNode swapPairs(ListNode head) {
		ListNode res_head = new ListNode(0, null);
		ListNode even_head = new ListNode(0, null);
		ListNode even_trav = even_head;
		ListNode odd_head = new ListNode(0, null);
		ListNode odd_trav = odd_head;

		int counter = 0;
		while (head != null) {
			if (counter % 2 == 0) {
				even_trav.next = head;
				even_trav = even_trav.next;
			} else {
				odd_trav.next = head;
				odd_trav = odd_trav.next;
			}

			head = head.next;
			counter++;
		}

		head = res_head.next;
		even_trav = even_head.next;
		odd_trav = odd_head.next;
		counter = 0;
		while (even_trav != null && odd_trav != null) {
			if (counter % 2 == 0) {
				head = odd_trav;
				odd_trav = odd_trav.next;
			} else {
				head = even_trav;
				even_trav = even_trav.next;
			}
			counter++;
			head = head.next;
		}

		if (even_trav != null) {
			head = even_trav;
			head = head.next;
		}

		if (odd_trav != null) {
			head = odd_trav;
			head = head.next;
		}

		return res_head.next;
    }
}
