struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    bool hasDuplicate(struct ListNode* root) {
        if (root -> next == nullptr) return false;
        if (root -> val == root -> next -> val) return true;
        else return false;
    }

    struct ListNode* deleteDuplicates(struct ListNode* head) {
        if (head == nullptr) return nullptr;
        if (head -> next == nullptr) return head;
        struct ListNode* temp = head;
        while (temp -> next != nullptr) {
            if (this -> hasDuplicate(temp)) {
                struct ListNode *another_temp = temp -> next;
                temp -> next = another_temp -> next;
                continue;
            }
            temp = temp -> next;
        }
        return head;
    }
};
