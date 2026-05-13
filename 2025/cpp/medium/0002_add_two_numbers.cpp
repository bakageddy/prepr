struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
		ListNode dummy_bhava = ListNode(0);
		ListNode *result = &dummy_bhava;
		int carry = 0;
		while (l1 || l2) {
			int a = l1 == nullptr ? 0 : l1 -> val;
			int b = l2 == nullptr ? 0 : l2 -> val;
			int sum = a + b + carry;
			if (sum >= 10) carry = 1;
			else carry = 0;
			result -> next = new ListNode(sum % 10);
			result = result -> next;
			l1 = l1 == nullptr ? nullptr : l1 -> next;
			l2 = l2 == nullptr ? nullptr : l2 -> next;
		}
		if (carry == 1) {
			result -> next = new ListNode(1);
		}
		return dummy_bhava.next;
    }
};
