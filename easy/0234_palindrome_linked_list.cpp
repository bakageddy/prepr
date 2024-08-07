struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    bool isPalindrome(ListNode* head) {
		if (head == nullptr) return false;
		ListNode *fast = head;
		ListNode *slow = head;
		while (fast != nullptr && fast -> next != nullptr) {
			fast = fast -> next -> next;
			slow = slow -> next;
		}

		ListNode *prev = nullptr;
		ListNode *curr = slow;
		while (curr) {
			ListNode *next = curr -> next;
			curr -> next = prev;
			prev = curr;
			curr = next;
		}

		while (prev) {
			if (head -> val != prev -> val) {
				return false;
			}
			prev = prev -> next;
			head = head -> next;
		}
		return true;
    }
};
