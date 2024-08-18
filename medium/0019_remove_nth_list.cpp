struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
		ListNode *fast = head;
		ListNode *slow = head;
		while (fast && n > 0) {
			fast = fast -> next;
			n--;
		}
		while (fast && fast -> next != nullptr) {
			slow = slow -> next;
			fast = fast -> next;
		}
		ListNode *next = slow -> next;
		if (!next) slow -> next = nullptr;
		else slow -> next = next -> next;
		return head;
    }
};
