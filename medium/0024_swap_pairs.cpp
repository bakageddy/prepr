struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
		if (head == nullptr || head -> next == nullptr) return head;
        ListNode *next = head -> next;
        head -> next = head -> next -> next;
        next -> next = head;
        next -> next -> next = swapPairs(next -> next -> next);
        return next;
    }
};
